#include <stdio.h>
/*
实例中 count 作为全局变量可以在函数内使用，thingy 使用 static 修饰后，不会再每次调用时重置。
 */


static int count = 10;
void func(void);


int main()
{
    while(count--)
    {
        func();
    }
    return 0;
}

void func()
{
    static int thingh = 5;
//    int thingh = 5;
    thingh++;
    printf("thingh 为 %d,count 为 %d\n",thingh,count);
}
