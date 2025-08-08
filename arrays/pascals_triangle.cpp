#include <bits/stdc++.h>
using namespace std;


vector<int> generaterow(int row)
{
    long long ans=1;
    vector<int> ansrow;
    ansrow.push_back(ans);
    for(int i=1; i<row; i++)
    {
        ans=(ans*(row-i))/i;
        ansrow.push_back(ans);
    }
    return ansrow;

}
vector<vector<int>> answer(int row)
{
   vector<vector<int>> answer;
   for(int i=1; i<=row;i++)
   {
     answer.push_back(generaterow(i));
   }
   return answer;
}
int main()
{

   int row=5;
   vector<vector<int>> value=answer(row);
   for (const auto& val : value) {
        for (const auto& col : val) {
            cout << col << " ";
        }
        cout << endl;
    }




}

//also check the code for what is the elemnt on the given row and column