// 自己编写的strcat功能的函数
#include <iostream>
#include <cstring>
using namespace std;
void mystrcat(char * s1, char * s2, int len = 0);  //len 的缺省值为
int main()
{
    char str1[80] = "This is a test";
    char str2[80] = "0123456789";
    mystrcat(str1,str2,5); //只需要连接个字符
    cout << str1 << "\n";
    strcpy(str1, "this is a test"); //重置字符串str1
    mystrcat(str1,str2); //把整个字符串进行连接
    cout << str1 << "\n";
    return 0;
}
//自己定义的strcat功能的函数
void mystrcat(char * s1, char * s2, int len)
{
    //找s1的尾部
    while(*s1) s1++;
    if (len == 0 )
    len = strlen(s2);
    while(*s2 && len )
    {
        *s1 = *s2;  //复制字符
        s1++;
        s2++;
        len--;
    }
    *s1 ='\0';  //标记是s1结束
}



