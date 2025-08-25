#include <bits/stdc++.h>

using namespace std;
vector<int> majority(vector<int> &arr)
{
    int cnt1 = 0;
    int cnt2 = 0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
 
        if (cnt1 == 0 && arr[i] != el2)
        {
            el1 = arr[i];
            cnt1++;
        }
        else if (cnt2 == 0 && arr[i] != el1)
        {
            el2 = arr[i];
            cnt2++;
        }
        else if (el1 == arr[i])
        {
            cnt1++;
        }
        else if (el2 == arr[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == el1)
        {
            count1++;
        }
        if (arr[i] == el2)
        {
            count2++;
        }
    }
    if (count1 > (arr.size() / 3))
    {
        ans.push_back(el1);
    }
     if (count2 > (arr.size() / 3))
    {
        ans.push_back(el2);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,1,1,1,3,2,2,2};
    vector<int> k = majority(arr);
    for(auto val : k)
    {
        cout<< val<<" ";
    }
}
