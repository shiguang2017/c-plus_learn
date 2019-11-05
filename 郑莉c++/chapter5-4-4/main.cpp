#include <iostream>
#include <cmath>

//类的友元函数
using namespace std;

class Point
{
    public:
        Point(int x=0,int y=0):x(x),y(y){}
        int getX(){return x;}
        int getY(){return y;}
        friend float dist(Point &p1,Point &p2);   //友元函数声明
    private:
        int x,y;
};

//通过友元函数访问类的私有数据成员
float dist(Point &p1,Point &p2)   //友元函数定义（实现），
{
    double x=p1.x-p2.x;           //通过对象访问私有数据成员
    double y=p1.y-p2.y;
    return static_cast<float>(sqrt(x*x+y*y));
}

int main()
{
    Point myp1(1,1),myp2(5,5);
    cout<<"The distance is:";
    cout << dist(myp1,myp2) << endl;
    return 0;
}
