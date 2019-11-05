#include "point.h"
#include <iostream>

using namespace std;

//Point::Point() //构造函数
//{
//    x=0;
//    y=0;
//    cout<<"Default Constructor called."<<endl;
//}

Point::Point():x(0),y(0) //构造函数
{
    cout<<"Default Constructor called."<<endl;
}

//Point::Point(int x,int y):x(x),y(y)   //带参数构造函数
//{
//    cout<<"Constructor called."<<endl;
//}

Point::Point(int x,int y)   //带参数构造函数
{
    x=x;
    y=y;
    cout<<"Constructor called."<<endl;
}

Point::~Point()
{
    cout<<"Destructor called."<<endl;
}

void Point::move(int newX,int newY)
{
//    cout<<"Moving the point to("<<newX<<","<<newY<<")"<<endl;
    x=newX;
    y=newY;
}
