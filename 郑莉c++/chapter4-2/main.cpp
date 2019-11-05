#include <iostream>

using namespace std;
//复制构造函数

class Point
{
    public:
        Point(int xx=0,int yy=0)
        {
            x=xx;
            y=yy;
        }
        Point(Point &p);
        int getX()
        {
            return x;
        }
        int getY()
        {
            return y;
        }
    private:
        int x,y;
};

//成员函数的实现
Point::Point(Point &p)
{
    x=p.x;
    y=p.y;
    cout<<"Calling the copy constructor"<<endl;
}

//形参为Point类对象的函数
void fun1(Point p)
{
    cout<<p.getX()<<endl;
}

//返回值为Point类对象的函数
Point fun2()
{
    Point a(1,2);
    return a;
}

int main()
{
    Point a(4,5);      //第一个对象
    Point b=a;          //情况一，用a初始化b，第一次调用复制构造函数
    cout << b.getX() << endl;
    fun1(b);          //情况二，对象b作为fun1的实参，第二次调用复制构造函数
//    cout<<b.getX()<<endl;
    b=fun2();         //情况三，函数的返回值是类对象，函数返回时，调用复制构造函数
    cout<<b.getX()<<endl;
    return 0;
}
