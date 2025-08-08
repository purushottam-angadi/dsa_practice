#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leaders(vector<int> &arr)
{
 int maxi=0;
 int n= arr.size();
 vector<int> answer;
 for(int i=n-1; i>=0;i--)
 {
  
    if(maxi<=arr[i])
    {
        maxi=arr[i];
        answer.push_back(arr[i]);
    }

 }
 return answer;
}





int main()

{

  vector<int> arr1 = {1, 2, 3, 4, 5, 12, 8, 9, 10};
    vector<int> ans=leaders(arr1);
  for( auto val: ans)
  {
    cout<< val<<" ";
  }
  

}