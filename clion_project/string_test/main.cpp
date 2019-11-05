#include <iostream>
#include <string>

using namespace std;
int main() {
    string CLASS[] = {"background", "aeroplane", "bicycle","bird", "boat","bottle","bus","car","cat",
                      "chair","cow","diningtable","dog","horse","motorbike","person","pottedplant","sheep",
                      "sofa","train","tvmonitor"};// label for all class
    for(int i=0;i<21;i++)
    {
        int j= -i;
        cout<<"CLASS["<<i<<"]="<<CLASS[j]<<endl;
    }

    return 0;
}