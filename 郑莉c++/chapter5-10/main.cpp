#include <iostream>
#include "ex5-10.h"
using namespace std;

/*
多文件结构，在头文件header中定义类或是函数，然后在实现文件中进行实现，最后在main文件中使用；
最后的两个文件需要通过#include 方式将定义的头文件包含，

*/

int main()
{
    Point a(4,5);
    cout<<"Point A:"<<a.getX()<<","<<a.getY();
    Point::showCount();

    Point b(a);
    cout<<"Point B:"<<b.getX()<<","<<b.getY();
    Point::showCount();

    return 0;
}
