#include <iostream>

using namespace std;
//函数重载

int sumofSquare(int a,int b)
{
    return a*a + b*b;
}

double sumofSquare(double a, double b)
{
    return a*a + b*b ;
}
int main()
{
    int m,n;
    //cout << "Enter two integer:"<<;
    cout<<"Enter two integer:"<<endl;
    cin>>m>>n;
    cout << "Their sum of square: " << sumofSquare(m,n) << endl;

    double x,y;
//    cout << "Enter two real number :"<<;
    cout<<"Enter two integer:"<<endl;
    cin>>x>>y;
    cout<<"Their sum of square :"<<sumofSquare(x,y)<<endl;
    return 0;
}

