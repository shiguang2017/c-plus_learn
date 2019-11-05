#include <stdio.h>

void swap(int *a,int *b);

int main()
{
    int a=10,b=20;
    printf("变换前a的值为%d，b的值为%d\n",a,b);
    printf("变换前a的地址为%d,b的地址为%d\n",&a,&b);
    swap(&a,&b);
    printf("变换后a的值为%d，b的值为%d\n",a,b);
    printf("变换后a的地址为%d,b的地址为%d\n",&a,&b);
    return 0;
}

void swap(int *a,int *b)
{
    int p;
    printf("*a的值为%d:，a的值为：%d\n",*a,a);
    printf("*b的值为%d:，b的值为：%d\n",*b,b);
    p = *a;
    *a = *b;
    *b = p;

}
