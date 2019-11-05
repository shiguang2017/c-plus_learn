#include <iostream>
#include <cmath>

//个人银行账户管理
using namespace std;

class SavingsAccount
{
    private:
        int id;            //账户
        double Balance;    //余额
        double rate;       //年利率
        int lastDate;      //上次变更余额的日期
        double accumulation;   //余额安日累加之和

        //记录一笔账，data为日期，amount为金额，desc为说明
        void record(int date,double amount);

        //获得到指定日期为止的存款金额安日累计值
        double accumulate(int date)const
        {
            return accumulation+Balance*(date-lastDate);
        }
    public:
        //构造函数
        SavingsAccount(int date,int id,double reta);
        int getID(){return id;}
        double getBalance(){return Balance;}
        double getRate(){return rate;}
        void deposit(int date,double amount);      //存入现金
        void withdraw(int date,double amount);     //取出现金

        //结算利息，每年1月1日调用该函数
        void settle(int date);

        //显示账户信息
        void show();

};

//SavingsAccount 类相关成员函数的实现

//构造函数
SavingsAccount::SavingsAccount(int date,int id,double rate):id(id),
    Balance(0),rate(rate),lastDate(date),accumulation(0)
{
    cout<<date<<"\t#"<<id<<"is created"<<endl;
}

void SavingsAccount::record(int date,double amount)
{
    accumulation = accumulate(date);
    lastDate=date;
    amount=floor(amount*100+0.5)/100;       //保留小数点后两位
    Balance+=amount;
    cout<<date<<"\t#"<<id<<amount<<"\t"<<Balance<<endl;
}

void SavingsAccount::deposit(int date,double amount)
{
    record(date,amount);
}

void SavingsAccount::withdraw(int date,double amount)
{
    if(amount>getBalance())
        cout<<"Error:not enough money"<<endl;
    else
        record(date,-amount);
}

void SavingsAccount::settle(int date)
{
    double interest=accumulate(date)*rate/365;  //计算年息
    if(interest!=0)
        record(date,interest);
    accumulation=0;
}

void SavingsAccount::show()
{
    cout<<"#"<<id<<"\tBalance: "<<Balance;
}


int main()
{
    //建立几个账户
    SavingsAccount sa0(1,21325320,0.015);
    SavingsAccount sa1(1,58320212,0.015);
    //几笔账目
    sa0.deposit(5,5000);
    sa1.deposit(25,10000);
    sa0.deposit(45,5500);
    sa1.withdraw(60,4000);
    //开户后第90天到了银行的计息日，结算所有账户的年息
    sa0.show();cout<<endl;
    sa1.show();cout<<endl;
    return 0;
}
