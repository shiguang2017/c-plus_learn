#include <iostream>
#include <cstdlib>

using namespace std;

#define random(a,b) (rand()%(b-a+1)+a)

//冒泡法排序
int main()
{
   int nums[10];
   int a,b,t;
   int size;
   int i;

   size = 10;

   for(i = 0;i < 10;i++)
   {
//        nums[i]=rand();
       nums[i]=random(1,100);
   }
//    cout << "Original array is:" << endl;
   cout <<"排序前的数组：" <<endl;

    for(i = 0;i < 10;i++)
    {
       cout << nums[i] << ' ';
    }
    cout << "\n";

    for(a=0;a<size-1;a++)
    {
        for(b=size-1;b>=a;b--)
        {
            if(nums[b-1]>nums[b])
            {
                t=nums[b];
                nums[b]=nums[b-1];
                nums[b-1]=t;
            }
        }
    }

    cout << "排序后的数组：" << endl;
    for(i = 0;i < 10;i++)
    {
       cout << nums[i] << ' ';
    }

    cout <<endl;
    return 0;
}
