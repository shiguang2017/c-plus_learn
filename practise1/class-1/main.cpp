// 为TwoDShape类增加构造函数
#include <iostream>
#include <cstring>
using namespace std; //二维对象类
class TwoDShape
{
    double width;
    double height;
    public:
    //构造函数
    TwoDShape(double w,double h)
    {
         width = w;
         height = h;
    }
    void showDim()
    {
        cout << "Width and height are "
        << width  << " and " << height << "\n";
    }
    //访问函数
    double getWidth() { return width; }
    double getHeight() { return height; }
    void setWidth(double w ) { width = w;  }
    void setHeight(double h ) { height = h; }
};
//Triangle类是从TwoDShape类中继承而来的
class Triangle : public TwoDShape
{
    char style[20];
    public:
    // 构造函数
    Triangle( char *str, double w, double h):TwoDShape(w,h)
    {
        strcpy(style,str);
    }
    double area()
    {
        return getWidth() * getHeight() / 2;
    }
    void showStyle()
    {
        cout << "Triangle is " << style << "\n";
    }
};
int main()
{
    Triangle t1("isosceles",4.0,4.0);
    Triangle t2("right", 8.0, 12.0);
    cout << "Info for t1:\n";
    t1.showStyle();
    t1.showDim();
    cout << "Area is  " << t1.area() << "\n";
    cout << "\n";
    cout << "Info for t2:\n";
    t2.showStyle();
    t2.showDim();
    cout << "Area is  " << t2.area() << "\n";
    return 0;
}









