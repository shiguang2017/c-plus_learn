#include <iostream>
#include <string>
/*
/c++中构造函数和析构函数的继承问题

*/

using namespace std;

class father
{
public:
    father(){cout << "My Name is father"<<endl;}
    void printName()
    {
        cout <<"父类调用"<<endl;
    }
};


class son:father
{
public:
    son(){cout <<"子类调用"<<endl;};
    void print_sonName()
    {
        cout<<"子类调用"<<endl;
    }
};


int main()
{
    father father1;
    father1.printName();
    son son1;
    son1.print_sonName();
}