#include <iostream>
using namespace std;
/*
 int类型的指针每次加１，数值变化４个字节；
 ｄｏｕｂｌｅ类型的指针每次加１，数值变化８个字节
*/
int main ()
{
    int *i,j[10];
    double *f, g[10];
    int x=0;
    i = j;
    f = g;
    for ( x = 0; x < 10; x++ )
    {
        cout << i+x << ' ' << f+x << '\n';
    }

    cout << x << endl;
    return 0;
}
