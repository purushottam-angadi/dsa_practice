#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a, int N)
{

    int i = 1;
    for (int j = 0; j <N; j++)
    {
        if(a[j]!=i)
        {
            return i;
        }
        else{
            i++;
        }
    }
}
int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}




// another approach
// int missingNumber(vector<int> &a, int N)
// {
//     int total = N * (N + 1) / 2;
//     int sum = accumulate(a.begin(), a.end(), 0);
//     return total - sum;
// }