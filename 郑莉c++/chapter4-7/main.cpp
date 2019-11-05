#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
//结构体

struct Student
{
    int num;
    string name;
    char sex;
    int age;
};

int main()
{
    Student stu={9700,"Lin Lin",'F',19};
    cout<<"Num: "<<stu.num<<endl;
    cout<<"Name: "<<stu.name<<endl;
    cout<<"Sex: "<<stu.sex<<endl;
    cout<<"Age: "<<stu.age<<endl;
    return 0;
}
