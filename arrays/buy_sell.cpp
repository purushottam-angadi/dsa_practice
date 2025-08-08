#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
  int maxprofit=0;
  int mini=prices[0];
  for(int i=1; i<prices.size();i++)
  {
    int cost= prices[i]- mini;
    maxprofit=max(maxprofit,cost);
    mini= min(mini,prices[i]);
  }
  return maxprofit;
}





int main()

{

  vector<int> arr1 = {1, 2, 3, 4, 5, 7, 8, 9, 10};
  cout<<maxProfit(arr1)<<endl;

}