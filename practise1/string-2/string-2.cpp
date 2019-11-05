//把一个字符串转换为大写的
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main ()
{
   char str[80];
   int i;
   strcpy(str, "This is a test");
   cout << "原始字符串: " << str <<endl;
   for ( i = 0; str[i]; i++ )
   {
       str[i] = toupper(str[i]);
   }
   cout <<"变换后字符串: " << str <<endl;
   return 0;
}
