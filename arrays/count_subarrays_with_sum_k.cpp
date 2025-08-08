#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int counting(vector<int> &arr)
{
    unordered_map<int, int> mpp;
    int presum = 0;
    int n = arr.size();
    int cnt = 0;
    mpp[presum] += 1;
    int k = 3;
    for (int i = 0; i < n; i++)
    {

        presum += arr[i];

        if (mpp.find(presum - k) != mpp.end())
        {
            cnt = cnt + mpp[presum - k];
        }
        
        mpp[presum] += 1;
    }
    return cnt;
}

int main()

{

    vector<int> arr1 = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << counting(arr1) << endl;
}