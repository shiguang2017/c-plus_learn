#ifndef SUITCASETRACKING_H
#define SUITCASETRACKING_H




#include "dasiamrpn.h"

enum TrackingState
{
    tentative=0,

    conform,

    idle,

};

class SuitCaseTracking
{
public:
   SuitCaseTracking();
	void  init();
	void start(cv::Mat frame,cv::Rect &CureentPos,float &Trackingscore);
	 void trackinginit(const cv::Mat& mat, BoxInfo& info);
    TrackingState staus=idle;

    int _framecout=0;
    cv::Rect _rectbegin;
    cv::Rect _rectbefore;
     cv::Rect _priorepoch;

    struct timeval _start;




   
    ~SuitCaseTracking()
    {
       if(tracker!=NULL)
       {
         delete tracker;
       }
    }

private:
		DaSiamRPNTracker * tracker=NULL;


};

#endif // SUITCASETRACKING_H
