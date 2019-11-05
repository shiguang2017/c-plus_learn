#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    vector<char>vec;
    vector<char>::iterator ite;
    vector<char>::iterator p;
    vec.push_back('A');
//    vec.push_back('A');
//    vec.push_back('A');
    vec.push_back('B');
    vec.push_back('C');
//    vec.push_back('B');
//    vec.push_back('B');
    vec.push_back('D');
//    vec.push_back('A');
//    vec.push_back('A');
    cout<<"vec = "<<vec.data()<<endl;
//    p=remove(vec.begin(),vec.end(),'B');
//    cout<<"p = "<<p<<endl;
//    p=vec.erase(remove(vec.begin(),vec.end(),'A'),vec.end());
    for(ite=vec.begin();ite!=vec.end();ite++)
        cout<<*ite<<" "<<endl;
    vec.erase(remove(vec.begin(),vec.end(),'A'),vec.end());
    cout<<"vec = "<<vec.data()<<endl;
//    cout<<vec.end()-p<<endl;
    for(ite=vec.begin();ite!=vec.end();ite++)
       cout<<*ite<<" ";
    cout<<endl;
//    cout<<"vec = "<<vec.data()<<endl;
    return 0;

}