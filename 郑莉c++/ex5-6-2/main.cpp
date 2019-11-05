#include <iostream>
#include "extern_exam.h"
using namespace std;

/*
 主文件中是对i进行定义和声明，而extern_exam中对i的声明只是引用性声明，
 表示 extern_exam需要使用i变量。


 */


int i=3;
void next();
int main()
{
    cout<<"原始i="<<i<<endl;
    i++;
    cout<<"调用i++之后i="<<i<<endl;
    next();
    return 0;
}

void next()
{
    i++;
    cout<<"函数next中i++之后i="<<i<<endl;
    other();
}
