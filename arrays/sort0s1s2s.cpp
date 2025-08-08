#include <bits/stdc++.h>

using namespace std;
vector<int> sorting012(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int mid=0;
    int temp;
    while (mid <= high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            mid++; low++;
        }
        else if(arr[mid]==1)
        {
            mid++; 
        }
       else
        {
            swap(arr[mid],arr[high]);
            mid++; high--;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    vector<int> k = sorting012(arr);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
