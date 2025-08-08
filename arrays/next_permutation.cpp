#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> next_permutation(vector<int>& arr) {

   int index=-1;
   int n=arr.size();
   for(int i=n-2; i>=0; i--)
   {
    if(arr[i]<arr[i+1])
    {
        index=i;
        break;
    }
   }

   if(index==-1)
   
   {
    reverse(arr.begin(), arr.end());
   }

   for(int i=n-1; i>=index; i--)
   {
     if(arr[i]>arr[index])
     {
        swap(arr[i],arr[index]);
     }
   }

  reverse(arr.begin() + index + 1, arr.end()); // ✅ Correct usage
   return arr;
}

int main()
{
    vector<int> a = {1,2,3};
    vector<int> answer = next_permutation(a);
    for(auto val: answer)
    {
        cout<<val<<" ";
    }
    
  
}
