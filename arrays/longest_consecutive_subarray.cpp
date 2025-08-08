#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int consecutive(vector<int> &arr)
{
 unordered_set<int> st;
 int longest=1;

 for(int i=0; i<arr.size();i++)
 {
     st.insert(arr[i]);
    
 }
 for (auto val: st)
 {
    if(st.find(val-1)==st.end())
    {
        int cnt=1;
        int x=val;
        while(st.find(x+1)!=st.end())
        {
            x=x+1;
            cnt++;
        }
        longest=max(cnt,longest);
    }
 }
 return longest;

}





int main()

{

  vector<int> arr1 = {1, 2, 3, 4, 5, 12, 8, 9, 10};
  cout<<consecutive(arr1)<<endl;
  
  

}