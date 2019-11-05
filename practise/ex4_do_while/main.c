#include <stdio.h>
//do...while 循环与 while 循环类似，但是 do...while 循环会确保至少执行一次循环。

int main()
{
    /*局部变量定义 */
    int a = 10;
    /*do 循环执行*/
    do
    {
        printf("a 的值：%d\n",a);
        a += 1;

    }while(a<15);

    return 0;
}
