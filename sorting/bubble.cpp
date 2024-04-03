//Bubble sorting
#include <iostream>
using namespace std;

int main()
{
    //int demo[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};
     int n;
     cout<<"enter the number of elements:"<<endl;
     cin>>n;
     int demo[n];
     //inputing:
     for(int i=0;i<n;i++){
        cin>>demo[i];
     }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (demo[i] > demo[j])
            {
                int temp = demo[i];
                demo[i] = demo[j];
                demo[j] = temp;

                // cout << endl << demo[j] << " ->  <- " << demo[i] << endl;
                // for (int k = 0; k < 10; k++)
                // {
                //     cout << demo[k] << ", ";
                // }
            }
        }
    }

    cout << endl << "final answer: ";
    for (int k = 0; k < n; k++)
    {
        cout << demo[k] << ", ";
    }
}