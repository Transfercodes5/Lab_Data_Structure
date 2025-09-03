#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();

        for(int i=0;i<(n-1);i++)
        {
            for(int j=0;j<(n-i-1);j++)
            {
                if(arr[j] > arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

        // for(int i=0;i<n;i++)
        // {
        //     if(arr[i] == 0)
        //     {

        //     }
        // }

        cout<<"[";
        for(int i=0;i<n-1;i++)
        {
            cout<<arr[i]<<", ";
        }
        cout<<arr[n-1]<<"]";
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 7, 5}; //12
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //15
    vector<int> arr3 = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}; //2

    sol.sort012(arr3);
}