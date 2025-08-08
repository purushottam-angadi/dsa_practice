#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> answer( vector<vector<int>> &interval)
{ 
    vector<vector<int>> merged;
    sort(interval.begin(), interval.end());


    for(int i=0; i<interval.size();i++)
    {
        if( merged.empty() || merged.back()[1]<interval[i][0])
        {
             merged.push_back(interval[i]);
         
            
        }
        else{
           merged.back()[1]=max(interval[i][1], merged.back()[1]);
        }
    }
    
     return merged;

}
int main()
{
     vector<vector<int>> interval = {{1, 2},{3,5},{4,7},{8,10},{12,16}};
     vector<vector<int>> ans= answer(interval);
     
    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "] ";
    }
    cout << endl;


}