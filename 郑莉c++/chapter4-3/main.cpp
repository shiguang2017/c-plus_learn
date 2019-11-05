#include <iostream>

using namespace std;
class Clock
{
    public:
        Clock (int newH, int newM,int newS);     //构造函数
        void setTime(int newH,int newM,int newS);
        void showTime();
    private:
        int hour,minute,second;
};

Clock::Clock(int newH,int newM,int newS)
{
    hour=newH;
    minute=newM;
    second=newS;
}

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


int main()
{
    Clock c(0,0,0);
    c.showTime();
    c.setTime(8,30,30);
    c.showTime();
    return 0;
}
