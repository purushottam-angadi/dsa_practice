#include <bits/stdc++.h>

using namespace std;
int majority(vector<int> &arr)
{
   int cnt=0;
   int el;
   for(int i=0 ; i<arr.size();i++)
   {

   
   if(cnt==0)
   {
    el=arr[i];
    cnt++;
   }
   else if(el==arr[i]){
     cnt++;
   }
   else {
     cnt--;
   }
}
int count=0;
for(int i=0; i<arr.size(); i++)
{
   if(arr[i]==el)
   {
    count++;
   }
}
if(count> (arr.size()/2))
{
    return el;
}
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0,1,1,1,1};
    int k = majority(arr);
    cout<<k<<endl;
    
}
