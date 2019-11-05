#include <iostream>

using namespace std;
//类联函数以及函数的访问接口

class Clock           //时钟类的定义
{
    public:           //外部接口，公有成员函数
        void setTime(int newH=0,int newM=0,int newS=0);
        void showTime();
    private:         //私有成员函数
        int hour,minute,second;
};

//时钟类成员函数的具体实现
void Clock::setTime(int newH, int newM, int newS)
{
    hour = newH;
    minute = newM;
    second = newS;
}

//类联函数
inline void Clock::showTime()
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}

//主函数
int main()
{
    Clock myClock;       //定义对象myClock
    cout<<"First time set and output:"<<endl;
    myClock.setTime();   //设置时间为默认值
    myClock.showTime();  //显示时间
    cout<<"Second time set and output:"<<endl;
    myClock.setTime(8,30,30);
    myClock.showTime();
    return 0;
}

