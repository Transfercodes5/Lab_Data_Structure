#include<iostream>
using namespace std;

int main()
{

    int *ptr;
    int n = 4;

    ptr = new int[n];

    // cout<<sizeof(*ptr)<<endl;

    ptr[0] = 0;
    ptr[1] = 1;
    ptr[2] = 2;
    ptr[3] = 3;

    for(int i=0;i<n;i++)
    {
        cout<<ptr[i];
    }

    int m = 6;

    ptr = new int[m];

    for(int i=0;i<m;i++)
    {
        cout<<ptr[i];
    }
}
