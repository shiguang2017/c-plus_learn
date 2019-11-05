#include <iostream>

using namespace std;

const float PI=3.1415926;         //该出π的值
const float FENCE_PRICE=35;       //栅栏的单价
const float CONCRETE_PRICE=20;    //过道水泥的单价

class Circle                      //声明定义类Circle及其数据和方法
{
    public:                       //外部借口
        Circle(float r);          // 构造函数
        float circumference();    //计算圆的周长
        float area();             //计算圆的面积
    private:                      //私有数据成员
        float radius;             //圆半径
};

//构造函数初始化数据成员radius
Circle::Circle(float r)
{
    radius=r;
}

//计算圆的周长
float Circle::circumference()
{
    return 2*PI*radius;
}

//计算圆的面积
float Circle::area()
{
    return PI*radius*radius;
}


int main()
{
    float radius;
    cout << "Enter the radius of the pool:" << endl;
    cin>>radius;                 //提示用户半径输入
    Circle pool(radius);         //游泳池边界对象
    Circle poolRim(radius+3);    //栅栏对象

    //计算栅栏造价并输出
    float fenceCost=poolRim.circumference()*FENCE_PRICE;
    cout<<"Fencing Cost is $"<<fenceCost<<endl;


    //计算过道造价并输出
    float concreteCost=(poolRim.area()-pool.area())*CONCRETE_PRICE;
    cout<<"Concrete Cost is $"<<concreteCost<<endl;
    return 0;
}
