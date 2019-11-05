#include <iostream>
#include <cassert>

using namespace std;

class Point        //类定义
{
    public:        //外部接口
        Point():x(0),y(0) //构造函数
        {
            cout<<"Default Constructor called."<<endl;
        }

        Point(int x,int y)   //带参数构造函数
        {
            x=x;
            y=y;
            cout<<"Constructor called."<<endl;
        }
        ~Point()
        {
            cout<<"Destructor called."<<endl;
        }
        void move(int newX,int newY)
        {
            x=newX;
            y=newY;
        }
        int getX() const{return x;}
        int getY() const{return y;}
    private:    //私有数据成员
        int x,y;
};

class ArrayofPoints
{
    public:
        ArrayofPoints(int size):size(size)
        {
            points=new Point[size];
        }
        ~ArrayofPoints()
        {
            cout<<"Deleting..."<<endl;
            delete [] points;
        }

        //获得下标为index的数组元素
        //
//        Point &element(int index)
        Point &element(int index)
        {
            assert(index>=0&&index<size);
            return points[index];
        }
    private:
        Point *points;   //指向动态数组首地址
        int size;        //数组大小
};

int main()
{
    int count;
    cout << "Please enter the count of Points:" << endl;
    cin>>count;
    ArrayofPoints points();  //创建对象数组
    points.element(0).move(5,0);  //访问数组元素的成员
    points.element(1).move(15,20);  //访问数组元素的成员
    return 0;
}
