#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
using namespace cv;
int main()
{
    Mat srcImage=imread("/home/xionglin/NewDisk/345G/QT5/C++/practise2/cline_opencv1/test.png");
    imshow("原图",srcImage);
    Mat element=getStructuringElement(MORPH_RECT,Size(15,15));
    Mat dstImg; erode(srcImage,dstImg,element);
    imshow("腐蚀后",dstImg);
    waitKey(0);
}
