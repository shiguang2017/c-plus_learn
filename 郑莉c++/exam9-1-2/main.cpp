#include <iostream>

using namespace std;

template<typename T>
T abs(T x)
{
    return x<0?-x:x;
}

int main()
{
    int n=-5;
    double d=-5.5;
    cout << "n 的绝对值："<<abs(n) << endl;
    cout<<"d 的绝对值："<<abs(d)<<endl;
    return 0;
}
