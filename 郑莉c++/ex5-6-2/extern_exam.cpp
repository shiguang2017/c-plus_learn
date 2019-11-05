#include "extern_exam.h"
#include <iostream>
using namespace std;
extern int i;
void other()
{
    i++;
    cout<<"调用other函数之后i="<<i<<endl;
}
