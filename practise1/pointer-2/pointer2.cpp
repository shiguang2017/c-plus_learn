//给函数传入指针作为参数
#include <iostream>
using namespace std;
void f( int *j); //函数原型中需要指针作为参数
int main()
{
    int i;
    int *p;
    p = &i;
    f(p);
    cout << i <<endl; //i的值现在是了
    return 0;
}
//f()函数是接收一个指针作为参数
void f(int *j)
{
    *j = 100;
}
