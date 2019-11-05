#ifndef SUITCASEDETECTOR_H
#define SUITCASEDETECTOR_H

//#include "detector.h"
#include <map>


#include <opencv2/opencv.hpp>
using namespace std;


using namespace cv;
//class SuitCaseDetector : virtual public Detector{
class SuitCaseDetector {
public:
    SuitCaseDetector();

    ~SuitCaseDetector();
    int setConfig(const string& model_file, const string& weights_file);
    int detect(const cv::Mat& image, map<int, vector<pair<Rect,float>>>& result);


private:
    void  setMean(float *imagedata,Mat &src);
    void*  m_net;

    float* m_cnndata;
    int    m_netW;
    int    m_netH;
    int    m_channel;
};



#endif // SUITCASEDETECTOR_H
