//打印命令行参数
#include <iostream>

using namespace std;

int main(int argc, char *argv[] )

{
    for ( int i = 1; i < argc; i++ )
    {
        cout << argv[i] << "\n";
    }

    return 0;

}
