// #include <bits/stdc++.h>
// using namespace std;

// long long kadanessubarray(vector<int> &a)
// {
// int sum=0;
// int maxi=INT_MIN;
//     for(int i=0; i< a.size();i++)
//    {
//     sum+=a[i];
//     maxi=max(maxi,sum);
//     if(sum<0)
//     {
//         sum=0;
//     }
   
//    }
//    if(maxi<0) return 0;
//    return maxi;
// }
// int main()
// {

//     vector<int> a = {-2,-3,4,-1,-2,1,5,-3};
//     cout<<kadanessubarray(a)<<endl;
    
// }

// to print the array

#include <bits/stdc++.h>
using namespace std;

long long kadanessubarray(vector<int> &a)
{
int sum=0;
int maxi=INT_MIN;
int ansstart=-1;
int start=0;
int ansend=-1;
    for(int i=0; i< a.size();i++)
   {
    sum+=a[i];
    if(sum==0) start=i;
    if (sum>maxi)
    {
        maxi=sum;
        ansstart=start, ansend=i;

    }

    if(sum<0)
    {
        sum=0;
    }
   
   }
   if(maxi<0) return 0;
   return maxi;
}
int main()
{

    vector<int> a = {-2,-3,4,-1,-2,1,5,-3};
    cout<<kadanessubarray(a)<<endl;
    
}