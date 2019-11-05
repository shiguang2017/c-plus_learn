#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <time.h>
using namespace cv;

int otsu(Mat SrcImg)
{
    // calc Hist
    MatND Hist;
    const int nHistSize = 256;
    float range[] = {0, 255};
    const float *ranges[] = {range};
    const int channels = 0;
    calcHist(&SrcImg, 1, &channels, Mat(), Hist, 1, &nHistSize, &ranges[0], true, false);

    //Normalize & average pixel value
    int nImageSize = SrcImg.cols * SrcImg.rows;;
    float *pHist = (float*)Hist.data;
    float avgValue(0.0);
    float arrHist[256] = {0.0};
    for(int i = 0; i < 256; i++)
    {
        arrHist[i] = pHist[i] / nImageSize;
        avgValue += i * arrHist[i];
    }

    int nOTSUThd(0);
    float maxVariance(0.0);
    float w(0.0);
    float u(0.0);
    for (int i = 0; i < 256; i++)
    {
        w += arrHist[i];
        u += i * arrHist[i];

        float t = avgValue * w - u;
        float variance = t * t/(w*(1-w));

        if (variance > maxVariance)
        {
            maxVariance = variance;
            nOTSUThd = i;
        }
    }

    return nOTSUThd;
}


int main()
{
    clock_t start,end;
    Mat img=imread("/home/xionglin/NewDisk/345G/QT5/C++/practise2/cline_opencv_anna/1.bmp");
    Mat srcImage;
    cvtColor(img, srcImage, CV_BGR2GRAY);
    imshow("原图",srcImage);
//    Mat element=getStructuringElement(MORPH_RECT,Size(15,15));
    Mat dstImg;
////    erode(srcImage,dstImg,element);
    start=clock();
    int threah = otsu(srcImage);

    for(int i=0; i<srcImage.rows; i++)
    {
        for(int j=0; j<srcImage.cols; j++ )
        {
            if(srcImage.at<uint8_t >(i,j)>threah)
                srcImage.at<uint8_t>(i,j)=255;
            else
                srcImage.at<uint8_t>(i,j) = srcImage.at<uint8_t>(i,j);
        }
    }
    end=clock();
    printf("totile time=%f\n",(float)(end-start)*1000/CLOCKS_PER_SEC);
//    threshold(srcImage, dstImg, 80, 255, CV_THRESH_BINARY);
    imshow("腐蚀后",srcImage);
    waitKey(0);
}
