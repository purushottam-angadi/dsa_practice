#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS starting from node 'start'
bool detect(int src, vector<int> adj[], int vis[])
{
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node= q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it, node});
            }
            else if(parent!=it)
            {
                  return true;
            }
        }
    
       
    }
    false;

}

int main()
{
    int nodes = 9;
    vector<vector<int>> adj(nodes + 1);

   

    
}