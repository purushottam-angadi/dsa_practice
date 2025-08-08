#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 vector<vector<int>> sum_3(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i > 0 && arr[i] == arr[i - 1]) continue;


            int j = i + 1;
           int k = arr.size() - 1;
        
         
        while (j < k)
        {
            if (0 == arr[i] + arr[j] + arr[k])
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k+1]) k--;
                ans.push_back(temp);
            }
            else if (0< arr[i] + arr[j] + arr[k])
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}

int main()

{

    vector<int> arr1 = {-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2,2};
    int target = 9;
    vector<vector<int>> answer = sum_3(arr1);

    for (auto &triplet : answer) {
        for (int num : triplet) cout << num << " ";
        cout << "\n";
    }

    return 0;

}