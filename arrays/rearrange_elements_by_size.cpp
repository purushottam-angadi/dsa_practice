#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> rearrange(vector<int> &arr)
{
    vector<int> answer(arr.size());
    int posindex=0, negindex=1;
    for(int i=0 ; i<arr.size(); i++)
    {
        if(arr[i]>0)
        {
           answer[posindex]=arr[i];
           posindex+=2;
        }
        else{
           answer[negindex]=arr[i];
           negindex+=2;
        }
    }
    return answer;
}





int main()

{

  vector<int> arr1 = {1,2,-3,-1,-2,3,4,5};
  vector<int> ans=rearrange(arr1);
  for( auto val: ans)
  {
    cout<< val<<" ";
  }
  

}