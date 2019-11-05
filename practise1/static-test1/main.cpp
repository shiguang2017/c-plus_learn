//计算用户键入数值的平均值
#include <iostream>
using namespace std;
int running_arg(int i);
int main()
{
    int num;
    do
    {
        cout << "Enter numbers ( -1 to quit): ";
                cin >> num;
                if ( num != -1 )
        {
            cout << "Running average is : " << running_arg(num);
        }
    cout << "\n";  }while(num > -1);  return 0; }
int running_arg(int i)
{
 //由于sum和count都是静态的局部变量，所以函数
 //running_arg()被多次调用之间，它们的值是会被保留的。
    static int sum = 0, count = 0;
    sum = sum + i;
    count++;
    return sum / count;
}
