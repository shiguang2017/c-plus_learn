#include <stdio.h>
//告诉一个循环体立刻停止本次循环迭代，重新开始下次循环迭代。
int main()
{
    int a=10;
    do
    {
        if(a==15)
        {
            a+=1;
            continue;
        }
        printf("a 的值： %d\n",a);
        a++;
    }while(a<20);

    return 0;
}
