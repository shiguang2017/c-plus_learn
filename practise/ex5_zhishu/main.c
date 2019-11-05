#include <stdio.h>

int main()
{
    int i,j;
    for (i=2;i<=100;i++)
    {
        for(j=2;j<=100;j++)
        {
            if(!(i%j)) break;
        }
        if(i==j)
        {
            printf("%d 是质数\n",i);
        }
    }
    return 0;
}
