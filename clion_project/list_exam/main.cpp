#include <iostream>
#include <vector>
//#include<list>
//#include<string>
using namespace std;
int main() {
    vector<int> test;
    for(int j=0;j<100;j++)
    {
        test.push_back(0);
        test.push_back(1);
        if(j%3==0)
        test.erase(test.begin());
        //test.push_back(3);
        for(int i=0;i<test.size();i++)
        {
            cout<<test[i]<<endl;
        }
    }

//    cout << test << endl;
    cout<<"a&b:"<<(1^0)<<endl;
    return 0;
}