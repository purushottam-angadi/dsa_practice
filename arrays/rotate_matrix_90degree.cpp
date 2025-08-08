
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    int n= matrix.size();
    for(int i=0; i<=n-2;i++)
    {
        for(int j=i+1; j<=n-1;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}
int main()

{

    vector<vector<int>> arr1 = {{1,2,3,},{4,5,6,},{7,8,9}};
    vector<vector<int>> answer= rotateMatrix(arr1);
    for( auto it :answer)
    {
        cout<<"{";
        for(auto val: it)
        {
            cout<< val<< " ";
        }
        cout<<"}"<<endl;
    }
}