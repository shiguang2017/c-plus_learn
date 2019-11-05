#include<cstdlib>
#include<iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
    cv::Mat img; //定义一个Mat变量
    img = cv::imread("/home/xionglin/NewDisk/345G/QT5/C++/opencv_pro/qt_test1/te1/1.png"); //读取图片
    cv::imshow("window",img); //显示图片
    cv::waitKey(0);
    return 0;
}
