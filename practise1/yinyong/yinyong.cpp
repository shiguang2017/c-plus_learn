// 使用引用参数
#include <iostream>
using namespace std;
void f ( int &i ); //这里i是引用参数
int main()
{
    int val = 1;
    cout << "Old value for val: " << val << '\n';
    f(val);
    cout << "New value for val: " << val << '\n';
    return 0;
}

void f(int & i)
{
    i = 10; //这句将导致传入的参数的值被修改
}
