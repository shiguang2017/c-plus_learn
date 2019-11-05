#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
using namespace cv;
using namespace std;
int main(void)
{
    Mat image;
    image = imread("/home/xionglin/107G/Figure_1.png");
    namedWindow("display_image");
    imshow("display_image",image);
    waitKey();
    return 0;
}
