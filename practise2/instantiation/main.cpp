#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*
类的两种实例化方法
*/

class Student
{
    private:
        int age;
        string name;
    public:
        Student(int ,string );
        void show(int _age,string _name);
        void show2();
};

Student::Student(int _age,string _name)
{
//    this->age = _age;
//    this->name = _name;
    age = _age;
    name = _name;
}

void Student::show(int _age,string _name)
{
    cout<<"Age :"<<_age<<"\nName :"<<_name<<endl;
}

void Student::show2()
{
    cout<<"Age :"<<this->age<<"\nName :"<<this->name<<endl;
}

int main()
{
    Student s1(16,"xiaoming");
    s1.show(14,"lihuan");
    s1.show2();

    Student *s2 = new Student(45,"zhanghuang");
    s2->show2();
    return 0;
}
