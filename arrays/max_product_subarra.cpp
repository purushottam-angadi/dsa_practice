#include <bits/stdc++.h>
using namespace std;

long long maxprosubarray(vector<int> &a)
{
    int prefix=1;
    int suffix=1;
    int maxi=1;
    for(int i=0; i< a.size(); i++)
    {   
      if(suffix==0) suffix=1;
        if(prefix==0) prefix=1;

        prefix=a[i]*prefix;
        suffix=suffix*a[a.size()-i-1];
        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;

}
int main()
{

    vector<int> a = {2,9,0,9,5};
    cout<<maxprosubarray(a)<<endl;
    
}


//  Kadane's solution:- But this is not intuitive
// long long maxProductSubarray(vector<int> &a)
// {
//     long long maxProd = a[0];
//     long long minProd = a[0];
//     long long result = a[0];

//     for(int i = 1; i < a.size(); i++)
//     {
//         if(a[i] < 0)
//             swap(maxProd, minProd);

//         maxProd = max((long long)a[i], maxProd * a[i]);
//         minProd = min((long long)a[i], minProd * a[i]);

//         result = max(result, maxProd);
//     }

//     return result;
// }