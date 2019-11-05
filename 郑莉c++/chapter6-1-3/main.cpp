#include <iostream>
#include<point.h>

using namespace std;

int main()
{
    cout << "Entering main..." << endl;
//    Point a[2];      //调用默认构造函数
//    for(int i=0;i<2;i++)
//        a[i].move(i+10,i+20);
    Point a[2]={Point(1,2),Point(4,5)};
    a[0].move(1,2);
    a[1].move(4,5);

    cout <<"Exiting main..."<<endl;
    return 0;
}
