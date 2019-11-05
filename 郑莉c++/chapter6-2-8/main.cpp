#include <iostream>

using namespace std;
//指针

//将实数x分成整数部分和小数部分，形参intPart、fracPart是指针
void splitFloat(float x,int *intPart,float *fracPart)
{
//    *intPart=static_cast<int>(x);    //取x的整数部分
    *intPart=int(x);    //取x的整数部分
    *fracPart=x-*intPart;           //取x的小数部分
}

int main()
{
    cout << "Enter 3 float point numbers:" << endl;
    for (int i=0;i<3;i++)
    {
        float x,f;
        int n;
        cin>>x;
        splitFloat(x,&n,&f);
        cout << "Integer Part="<<n<<"\tFraction Part="<<f << endl;
    }
    return 0;
}
