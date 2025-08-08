#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxlength(string s)
{
    vector<int> hash(256,-1);
    int n=s.size();
    int maxlen=0;
    int left=0;
    for(int right=0; right<n; right++)
    {
        if(hash[s[right]]!=-1)
        {
            if(hash[s[right]]>=left)
            {
                left=hash[s[right]]+1;
            }

        }
          hash[s[right]]=right;
          maxlen=max(maxlen,right-left+1);
    }
    return maxlen;

}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: "
         << maxlength(s) << endl;
    return 0;
}



// // #include <iostream>
// #include <unordered_map>
// #include <string>
// using namespace std;

// int maxlength(string s) {
//     unordered_map<char, int> hash;
//     int maxlen = 0;
//     int left = 0;

//     for (int right = 0; right < s.length(); ++right) {
//         char ch = s[right];

//         // If character is already in the map and within the current window
//         if (hash.find(ch) != hash.right() && hash[ch] >= left) {
//             left = hash[ch] + 1; // move left to avoid repeat
//         }

//         hash[ch] = right; // update last seen index
//         maxlen = max(maxlen, right - left + 1);
//     }

//     return maxlen;
// }

// int main() {
//     string s = "abcabcbb";
//     cout << "Length of longest substring without repeating characters: "
//          << maxlength(s) << rightl;
//     return 0;
// }