//inserting sorting:
#include <iostream>
using namespace std;
// THE CODE IS NOT COMPLETED
class Test
{
private:
int demo[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};
    //  int n;
    //  cout<<"enter the number of elements:"<<endl;
    //  cin>>n;
    //  int demo[n];
    //  //inputing:
    //  for(int i=0;i<n;i++){
    //     cin>>demo[i];
    //  }

public:
    void exchange(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    void mainProcess(){
        exchange(demo[1],demo[4]);

        for(int i=0;i<10;i++)
        {
            cout<<demo[i]<<", ";
        }
    }
};

int main()
{
    Test t1;
    t1.mainProcess();
    return 0;
}