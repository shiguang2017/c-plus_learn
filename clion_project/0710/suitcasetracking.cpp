#include "suitcasetracking.h"
#include <iostream>
 SuitCaseTracking::SuitCaseTracking()
{
   

   _priorepoch=cv::Rect(0,0,0,0);
   _rectbefore=cv::Rect(0,0,0,0);
   _rectbegin=cv::Rect(0,0,0,0);

   
}
void  SuitCaseTracking::init()
{

	std::string temple_net_file = "/root/gs_ws/src/suitcase/src/lossbox/init.pt";
	std::string track_net_file = "/root/gs_ws/src/suitcase/src/lossbox/track.pt";
	tracker = new DaSiamRPNTracker(temple_net_file,track_net_file);

}

void  SuitCaseTracking::start(cv::Mat frame,cv::Rect &CureentPos,float &Trackingscore)
{
    float score=0;
	float x=0,y=0,w=0,h=0;
	tracker->SiamRPN_track(frame,x,y,w,h,score);
	std::cout<<"4444"<<std::endl;
	
	CureentPos=cv::Rect((int)((x-w/2)>0?(x-w/2):0),(int)((y-h/2)>0?(y-h/2):0),(int)w,(int)h);
	//CureentPos=cv::Rect((int)(x-w/2),(int)(y-h/2),(int)w-1,(int)h-1);
	CureentPos &= cv::Rect(0,0,frame.cols,frame.rows);
	Trackingscore=score;
}

void SuitCaseTracking::trackinginit(const cv::Mat& mat, BoxInfo& info)
{

	tracker->SiamRPN_init ( mat,info );


}



