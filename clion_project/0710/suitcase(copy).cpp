#include <sys/time.h>
#include <iostream>
#include <thread>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "suitcasetracking.h"
#include "suitcasedetector.h"

#include <ros/console.h>
#include "sql_node/common_return.h"
#include "sql_node/custom_return.h"
#include "sql_node/imageinfo.h"

#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>


#define DEBUG

using namespace cv;
using namespace std;

SuitCaseDetector suitdetector;
SuitCaseTracking suittracking;

static ros::Publisher suitcase_pub_resbon;
static ros::Publisher suitcase_pub_Carryover;
static ros::Publisher chatter_pub_receive;
int reciveImageFlag=0;
static cv::Mat img;
std::mutex m1;



volatile bool ThreadOn=false;
volatile bool threadoff=true;

void imageCallback ( const sensor_msgs::ImageConstPtr& msg )
{


	cv_bridge::CvImagePtr cv_ptr;
	try
	{
		cv_ptr = cv_bridge::toCvCopy ( msg, "bgr8" );
	}
	catch ( cv_bridge::Exception& e )
	{
		ROS_ERROR ( "cv_bridge exception: %s", e.what() );
		return;
	}
	m1.lock();
	img = cv_ptr->image;
	m1.unlock();
	reciveImageFlag=1;
	
}


bool overlapRoi ( const cv::Rect& r1, const cv::Rect& _r2, float& perc )
{
	int x_tl = fmax ( r1.x, _r2.x );
	int y_tl = fmax ( r1.y, _r2.y );
	int x_br = fmin ( r1.x + r1.width, _r2.x + _r2.width );
	int y_br = fmin ( r1.y + r1.height, _r2.y + _r2.height );
	int w, h;
	int minarea=_r2.area() >r1.area() ?r1.area() :_r2.area();
	if ( x_tl < x_br && y_tl < y_br )
	{
		w = x_br - x_tl;
		h = y_br - y_tl;
		perc = ( w*h ) / float ( minarea );
		return true;
	}
	perc = 0;
	return false;
}



bool SuitcaseThreadOn()
{

	map<int, vector<pair<Rect,float>>> res;
	std::map<int,vector<pair<Rect,float>>>::iterator iter;
	int FrameId=0;

	cv::Mat frame;


	ThreadOn=true;
	threadoff=false;
	//

	suitdetector.setConfig ( "/root/gs_ws/src/suitcase/src/lossbox/deploy.prototxt","/root/gs_ws/src/suitcase/src/lossbox/VGG_traindata_SSD_300x300_iter_70000.caffemodel" );
	suittracking.init();
	//ret.topicName="carryover_open";
	//ret.state=2;
	//ret.param=msg.req;

	//chatter_pub_receive.publish ( ret );
	while ( ThreadOn )
	{
		//get image
	    if ( ( !reciveImageFlag ) )
		{
			continue;
		}
	    //if(!img.data) break;

		m1.lock();
		img.copyTo ( frame );
		m1.unlock();

		FrameId++;
//#ifdef DEBUG
//		cv::imshow ( "tracking",frame );
//		cv::waitKey ( 10 );
//#endif


		res.clear();
		if ( suittracking.staus==idle )
		{
			BoxInfo binfo= {0};

			if ( FrameId%3==0 )
			{
				suitdetector.detect ( frame,res );
			}
			else
			{
				continue;
			}

			for ( iter=res.begin(); iter!=res.end(); iter++ )
			{
				int suitcase=iter->first;
				if ( suitcase==1 )
				{
					for ( auto itr=iter->second.begin(); itr<iter->second.end(); itr++ )
					{
						float varscore=itr->second;
						float iouscore=0.00;
						Rect rt=itr->first;
						overlapRoi ( rt,suittracking._rectbefore,iouscore );
						if ( iouscore-0.5>0.000001 )
						{
							continue;
						}
						else
						{
							binfo.xc=rt.x+rt.width/2;
							binfo.yc=rt.y+rt.height/2;
							binfo.w=rt.width;
							binfo.h=rt.height;

						}

					}

					break;
				}


			}

			if ( binfo.w!=0 && binfo.h!=0 )
			{
				suittracking.trackinginit ( frame,binfo );
				gettimeofday ( & ( suittracking._start ),NULL );
//cout<<binfo.xc<<binfo.w/2<<binfo.yc<<binfo.h/2<<endl;
				suittracking._rectbegin=Rect ( ( int ) ( binfo.xc-binfo.w/2 ), ( int ) ( binfo.yc-binfo.h/2 ), ( int ) ( binfo.w ), ( int ) ( binfo.h ) );
				suittracking._rectbefore=suittracking._rectbegin;
				suittracking._priorepoch=suittracking._rectbefore;
				suittracking._framecout=0;
				suittracking.staus=conform;

			}

		}
		else
		{
			cv::Rect currentrackingpos;
			float Trackingscore=0;
			suittracking.start ( frame, currentrackingpos,Trackingscore );
			suittracking._framecout++;
#ifdef DEBUG

			cv::rectangle ( frame,cv::Point ( currentrackingpos.x,currentrackingpos.y ),cv::Point ( currentrackingpos.x+currentrackingpos.width,currentrackingpos.y+currentrackingpos.height ),cv::Scalar ( 0,0,255 ) );

			cv::imshow ( "tracking",frame );
			cv::waitKey ( 10 );
#endif

		 if(Trackingscore-0.8<0.000001)
            {   //tracking loss
                suittracking.staus=idle;
                suittracking._priorepoch=cv::Rect(0,0,0,0);
                suittracking._rectbefore=cv::Rect(0,0,0,0);
                suittracking._rectbegin=cv::Rect(0,0,0,0);
                continue;
            }

		  if(suittracking._framecout%10==0)
		  {

		  	 float tentativeiou=0;
                overlapRoi(currentrackingpos,suittracking._priorepoch,tentativeiou);

				 if(tentativeiou<0.8)
                {
                    //moving obj
                   suittracking.staus=idle;
                   suittracking._rectbefore=currentrackingpos;
                    continue;
                }

				  struct timeval end;
                 gettimeofday(&end,NULL);
                 if((end.tv_sec-suittracking._start.tv_sec)>7)
				 	{
                    int diffx=(currentrackingpos.x+currentrackingpos.width/2)-(suittracking._rectbegin.x+suittracking._rectbegin.width/2);
                    int diffy=(currentrackingpos.y+currentrackingpos.height/2)-(suittracking._rectbegin.y+suittracking._rectbegin.height/2);

                    int distance=sqrt(diffx*diffx+diffy*diffy);

                    if(distance<currentrackingpos.width/2)
                    {
                    	sql_node::imageinfo imagemsg;
						cv_bridge::CvImage cvi;
						std::stringstream ss4;
						//cv::Rect rectsuit;
						
						ss4 <<"suitcase_carryover_warning";
						imagemsg.faceinfo = ss4.str();

						ros::Time time = ros::Time::now();
						//cvi.header.stamp = time;
						cvi.header.frame_id = "image";
						//cvi.encoding = "bgr8";
						cvi.image =frame(currentrackingpos).clone(); //Mat
						cvi.toImageMsg ( imagemsg.ros_img );

						suitcase_pub_Carryover.publish ( imagemsg );
						
                        //carry over suitcase
                        suittracking.staus=idle;
                        suittracking._rectbefore=currentrackingpos;
                         continue;


                    }
                    else
                    {
                        suittracking.staus=idle;
                        suittracking._rectbefore=currentrackingpos;
                         continue;

                    }
                  }

		  }
		}

	}





	ThreadOn=false;
	threadoff=true;
}

static vector<string> splitEx ( const string& src, string separate_character )
{
	vector<string> strs;
	int separate_characterLen = separate_character.size();//分割字符串的长度,这� �就可以支持如“,,”多字符串的分隔符
	int lastPosition = 0,index = -1;
	while ( -1 != ( index = src.find ( separate_character,lastPosition ) ) )
	{
		strs.push_back ( src.substr ( lastPosition,index - lastPosition ) );
		lastPosition = index + separate_characterLen;
	}
	string lastString = src.substr ( lastPosition ); //截取最后一个分隔符后的内容
	if ( !lastString.empty() )
	{
		strs.push_back ( lastString );    //如果最后一个分隔符后还有内容就入队
	}
	return strs;
}

void carryover_callback ( const sql_node::common_return& msg )
{
	std::cout<<"carryover_callback"<<std::endl;
	sql_node::custom_return ret;
	std::thread ThreadSuitcase;
	ret.id=msg.id;
	ret.topicName="carryover_open";
	ret.state=2;
	ret.param=msg.req;

	chatter_pub_receive.publish ( ret );

	std::string OffOpenFlag =msg.req;
        //string del=",";
	//vector<string> strs = splitEx ( OffOpenFlag, del );

	//bool m;
	//m=stoi ( strs[4].c_str() );
	if ( OffOpenFlag == "1" )
	{
		if ( ThreadOn==false )
		{

			ROS_ERROR_NAMED ( "suitcase","thread is lanuching" );

			ThreadSuitcase = std::thread ( SuitcaseThreadOn );
			ThreadSuitcase.detach();
			cout<<"start suitcase"<<endl;

		}
		else
		{
			ROS_DEBUG_NAMED ( "suitcase","thread have been lanuch" );
		}
	}
	else
	{
		if ( ThreadOn==true )
		{
			ROS_DEBUG_NAMED ( "suitcase","stop suitcase thread" );
	ros::NodeHandle nh;
nh.setParam ( "suitcase", "false" );

			ThreadOn=false;

			do
			{

			}
			while ( ! ( threadoff ) );
ros::shutdown();
           exit(0);

		}
		else
		{

			ROS_DEBUG_NAMED ( "suitcase","thread have been stop" );

		}

	}




}


int main ( int argc, char** argv )
{
	ros::init ( argc, argv, "suitcase" );
	ros::NodeHandle n;

	ros::Subscriber SuitcaseCarryoverOpen;

cout<<"suitcase is ok"<<endl;
	image_transport::ImageTransport it ( n );
	SuitcaseCarryoverOpen=n.subscribe ( "/carryover_open", 100, &carryover_callback,ros::TransportHints().tcpNoDelay ( true ) );
	image_transport::Subscriber imgesub = it.subscribe ( "image_raw2", 100, imageCallback );

	suitcase_pub_resbon = n.advertise<sql_node::custom_return> ( "/custom_return", 100 );
chatter_pub_receive= n.advertise<sql_node::custom_return>("custom_return", 100);
	suitcase_pub_Carryover = n.advertise<sql_node::imageinfo> ( "/suitcase_carryover_warning", 100);

	
	
	n.setParam ( "suitcase", "true" );

    ros::MultiThreadedSpinner s ( 2 );
	 ros::spin(s);

}




