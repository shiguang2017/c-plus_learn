/*
 工程 4-2
 原地对一个字符串进行倒置
*/
#include <iostream>
#include <cstring>
using namespace  std;
int main( )
{
    char str[] = "this is a test";
    char *start, *end;
    int len;
    char t;
    cout << "Original: " << str << "\n";
    len = strlen(str);
    start = str;
    end = &str[len-1];
    while ( start < end )
    {
        // swap chars
        t = *start;
        *start = *end;
        *end = t;
        //移动指针
        start++;
        end--;
    }
    cout << "Reversed:" << str << "\n";
    return 0;
}
