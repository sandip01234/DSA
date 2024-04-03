//Selection sorting:
#include <iostream>
using namespace std;

int main()
{
   // int demo[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};
         int n;
     cout<<"enter the number of elements:"<<endl;
     cin>>n;
     int demo[n];
     //inputing:
     for(int i=0;i<n;i++){
        cin>>demo[i];
     }
    int curr_min;
    int temp;

    for (int i = 0; i < n; i++)
    {
        curr_min = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (demo[j] < demo[curr_min])
            {
                curr_min=j;
            }
        }
        temp = demo[curr_min];
        demo[curr_min] = demo[i];
        demo[i] = temp;
    }

    for (int k = 0; k < n; k++)
    {
        cout << demo[k] << ", ";
    }
}