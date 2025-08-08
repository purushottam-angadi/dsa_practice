// #include<iostream>
// #include<string>
// #include<unordered_map>
// using namespace std;


// int longest(string s, int k)
// {
//     unordered_map<char,int> mpp;
//     int maxlen=0;
//     int l=0, r=0;
//     int cnt=0;
//     while(r<s.size())
//     {
//         mpp[s[r]]+=1;
     
//         if(mpp.size()>k)
//         {
//             mpp[s[l]]--;
//             if(mpp[s[l]]==0) mpp.erase(s[l]);
//             l=l+1;
//         }
//         if(mpp.size()<=k)
//         {
//             maxlen=max(maxlen,r-l+1);
//             cnt++;
//         }
//         r++;
//     }
// return cnt;
// }
// int main()
// {
//     string s={"abcbbca"};
//     int k=2;
//     int length= longest(s,3);
//     cout<<length<<endl;
// }
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int atMostK(string s, int k)
{
    unordered_map<char, int> mpp;
    int l = 0, count = 0;

    for (int r = 0; r < s.size(); r++)
    {
        mpp[s[r]]++;

        while (mpp.size() > k)
        {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0)
                mpp.erase(s[l]);
            l++;
        }

        count += (r - l + 1);
    }

    return count;
}

int countExactlyK(string s, int k)
{
    return atMostK(s, k) - atMostK(s, k - 1);
}

int main()
{
    string s = "abcbbca";
    int k = 3;
    int total = countExactlyK(s, k);
    cout << total << endl;
}