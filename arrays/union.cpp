#include<iostream>
#include<vector>
using namespace std;

vector<int> unionARR(vector<int> &arr1 ,vector<int> &arr2)
{
    vector<int> unionarr;
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0, j=0;
    
    while(i<n1 && j<n2)
    {
     if(arr1[i]<=arr2[j])
    {
      if( unionarr.empty() || unionarr.back()!= arr1[i] )
      {
        unionarr.push_back(arr1[i]);
      }
      i++;
    }
    else
    {
      if(unionarr.empty() || unionarr.back()!= arr2[j] )
      {
        unionarr.push_back(arr2[j]);
      }
      j++;
    }
    
    }
    while (i<n1)
    {
       if(unionarr.empty() || unionarr.back()!= arr1[i] )
      {
        unionarr.push_back(arr1[i]);
      }
      i++;
    }
      while (j<n2)
    {
        if(unionarr.empty() || unionarr.back()!= arr2[j] )
      {
        unionarr.push_back(arr2[j]);
      }
      j++;
    }

   return unionarr;
}



int main()

{

  vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Union = unionARR(arr1, arr2);
  
  for (auto val: Union)
    cout << val << " ";
  return 0;
}