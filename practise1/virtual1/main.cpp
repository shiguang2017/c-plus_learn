//一个用于演示虚函数的简短的程序
#include <iostream>
using namespace std;
class B
{
public:
    virtual void who() //声明为虚函数
    {
        cout << "Base\n";
    }
};
class D1 : public B
{
public:
    void who()//重新定义基类中的虚函数
    {
        cout << "First derivation\n";
    }
};
class D2 : public B
{
public:
    void who()//重新定义基类中的虚函数
    {
        cout << "Second derivation\n";
    }
};
int main()
{
    B base_obj;
    B *p;
    D1 D1_obj;
    D2 D2_obj;
    p = &base_obj;
    p->who();
    p = &D1_obj;
    p->who();
    p = &D2_obj;
    p->who();
    return 0;
}
