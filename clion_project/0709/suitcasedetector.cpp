#include "suitcasedetector.h"
#include <caffe/caffe.hpp>
//#include <caffe/proto/caffe.pb.h>

//using caffe::Net;
using namespace std;
using namespace caffe;

SuitCaseDetector::SuitCaseDetector()
{
    m_net = nullptr;
    m_cnndata = nullptr;
}

SuitCaseDetector::~SuitCaseDetector()
{
    Net<float> *pNet = static_cast<Net<float> *>(m_net);

    if(pNet)
    {
        delete pNet;

        m_net = nullptr;
    }
    if(m_cnndata)
    {
        free(m_cnndata);
        m_cnndata = nullptr;
    }
}

int SuitCaseDetector::setConfig(const string& model_file, const string& weights_file)
{
    Net<float> *pNet = static_cast<Net<float> *>(m_net);

    if(pNet)
    {
        delete pNet;

        m_net = nullptr;
    }
    if(m_cnndata)
    {
        free(m_cnndata);
        m_cnndata = nullptr;
    }
    Caffe::set_mode(Caffe::GPU);
    Caffe::SetDevice(0);
    pNet = new Net<float>( model_file, TEST);

    if(pNet)
    {
         pNet->CopyTrainedLayersFrom( weights_file );

         vector<Blob<float>*> blobs = pNet->input_blobs();

         m_net = pNet;

         m_channel = blobs[0]->channels();
         m_netH = blobs[0]->height();
         m_netW = blobs[0]->width();
         m_cnndata = static_cast<float*>(malloc(static_cast<unsigned int>(m_netH*m_netW*m_channel)*sizeof(float)));

         return 0;
    }
    else
    {
        return -1;
    }
}

static float dThreshold( float dValue)
{

    if( dValue < 0)
    {
        dValue = 0;
    }
    else if( dValue >1)
    {
        dValue = 1;
    }

    return dValue;
}

int SuitCaseDetector::detect(const cv::Mat& img, map<int, vector<pair<Rect,float>>>& result)
{
    if(m_net == nullptr || m_cnndata == nullptr)
    {
        return -1;
    }
    Mat dst(m_netH,m_netW,CV_8UC3);
    cv::Size size(m_netH,m_netW);
    cv::resize(img,dst,size);
    int imgW = img.cols, imgH = img.rows;

    setMean(m_cnndata,dst);

    float* resultData32;
    int resultLength = 0;
    Net<float> *pNet = static_cast<Net<float> *>(m_net);

    Blob<float> * blob_data = nullptr;
    blob_data = pNet->input_blobs()[0];
    blob_data->set_cpu_data( m_cnndata );
    std::vector<Blob<float>*> result_p = pNet->Forward();
    resultData32 = const_cast<float*>(result_p[0]->cpu_data());
    resultLength = result_p[0]->count( 0 );

    //get SSD detection results
    vector<vector<float>> detections;
    int out_count = resultLength/7;
    for(int i = 0; i <out_count; i++)
    {
        if(resultData32[i] <= -1)
        {//skip invalid detection
            resultData32 +=7;
            continue;
        }
        vector<float> detection(resultData32, resultData32+7);
        detections.push_back(detection);
        resultData32 +=7;
    }
    /*
     * split detections
     * 1. split result into seprate individuals
     * 2. get class type, confidence and rect
     * 3. combine confidence and rect into a pair
     * 4. insert the pair into map[class]
     * */
    result.clear(); //clear map
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    float dTemx1 = 0,dTemy1 = 0,dTemx2 = 0,dTemy2 = 0;
    int objClass = 0;
    Rect resultRect = {0,0,0,0};
    float confidence = 0;
    pair<Rect,float> resultPair(resultRect, confidence);
    unsigned int resultNum = static_cast<unsigned int>(detections.size());
    for(unsigned int i =0; i< resultNum; i++)
    {
        const vector<float> &d = detections[i];

        //limit d value in [0,1]
        dTemx1 = dThreshold(d[3]);
        dTemy1 = dThreshold(d[4]);
        dTemx2 = dThreshold(d[5]);
        dTemy2 = dThreshold(d[6]);

        //return to the original size
        x1 = int(dTemx1 * imgW );
        y1 = int(dTemy1 * imgH );
        x2 = int(dTemx2 * imgW );
        y2 = int(dTemy2 * imgH );

        if(x1<0) x1 = 0;
        if(y1<0) y1 = 0;

        if(x2>imgW) x2 = imgW;
        if(y2>imgH) y2 = imgH;

        resultRect.x = x1;
        resultRect.y = y1;
        resultRect.width = x2 - x1;
        resultRect.height = y2 - y1;

        if(resultRect.width<=0 || resultRect.height<=0)
        {
            continue;
        }
        objClass = static_cast<int>(d[1]);
        confidence = d[2];

        /*
         * put rect and confidence into pair;
         * insert pair into vector of the map;
         * */
        resultPair.first = resultRect;
        resultPair.second = confidence;
        result[objClass].push_back(resultPair);//insert ssd's result into result

    }

    return 0;
}


#define mean_b_value 104.0
#define mean_g_value 117.0
#define mean_r_value 123.0

void  SuitCaseDetector::setMean(float *imagedata,Mat &src)
{
    int x =0, y= 0;
    float * image_data_index;
    unsigned char * mat_buff_index;
    unsigned char * data = nullptr;
    int UnitW = src.cols,UnitH = src.rows;

    int offset_g = UnitW * UnitH;
    int offset_r = UnitW * UnitH * 2;


    data = src.data;
    memset(imagedata,0,sizeof(float)*static_cast<unsigned int>(UnitW*UnitH)*3);

    for(y = 0; y < UnitH; y ++)
    {
        image_data_index = imagedata +  y*UnitW;
        mat_buff_index   = data +  3*y*UnitW;

        for(x = 0; x < UnitW; x++)
        {
            image_data_index[x] = (static_cast<float>(mat_buff_index[3*x]) - static_cast<float>(mean_b_value));
            image_data_index[x + offset_g] = (static_cast<float>(mat_buff_index[3*x + 1]) - static_cast<float>(mean_g_value));
            image_data_index[x + offset_r]  = (static_cast<float>(mat_buff_index[3*x + 2]) - static_cast<float>(mean_r_value));
        }
    }
}
