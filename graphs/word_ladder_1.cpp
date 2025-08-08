#include<iostream>
#include<queue>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;


int wordladder(string start, string target, vector<string> &wordlist){
queue<pair<string,int>> q;

q.push({start,1});
unordered_set<string> st(wordlist.begin(), wordlist.end());
st.erase(start);
while(!q.empty())
{
   string word= q.front().first;
   int step= q.front().second;
   q.pop();
   if(word==target) return step;
   for(int i=0; i< word.size(); i++)
   {
     char original=word[i];
     for(char ch ='a'; ch<= 'z'; ch++)
     {
        word[i]= ch;
     
     if(st.find(word)!= st.end())
     {
        st.erase(word);
        q.push ({word, step+1});
     }
    }
    word[i]=original;

   }
}

return 0;

}

int main()
{
    vector<string> wordlist={"hit","dot","dog","lot","log","cog"};
    int steps= wordladder("hit","log",wordlist);
    cout<<steps<<endl;
}