#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longest(vector<int> &arr)
{
    unordered_map<int, int> mpp;
    int presum = 0;
    int n = arr.size();
    mpp[presum] = -1;
    int k = 0;
    int maxi = 0;
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];

        if (mpp.find(presum - k) != mpp.end())
        {
            length = i - mpp[presum - k];
            maxi = max(length, maxi);
        }
        if (mpp.find(presum) == mpp.end())
        {
            mpp[presum] = i;
        }
    }
    return maxi;
}

int main()

{

    vector<int> arr1 = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << longest(arr1) << endl;
}