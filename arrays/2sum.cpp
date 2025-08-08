#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int,int> sum_2(vector<int> &a , int target)
{
    sort(a.begin(), a.end());
    int n=a.size();
    int l=0; int r=n-1;
    while(l<r)
    {
    if(a[l]+a[r]==target)
    {
        cout<<"Yes"<<endl;
        return {l,r};

    }
     else if(a[l]+a[r]<target)
    {
        l++;
    }
     else
    {
        r--;
    }
}
cout<<"NO"<<endl;

}





int main()

{

  vector<int> arr1 = {1, 2, 3, 4, 5, 7, 8, 9, 10};
   int target=9;
   pair<int,int> answer=sum_2(arr1,target);
   cout<<answer.first<<" "<<answer.second<<endl;
  

}