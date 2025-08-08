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
        for(auto adjacentNode : adj[node])
        {
            if(!vis[adjacentNode])
            {
                vis[adjacentNode]=1;
                q.push({adjacentNode, node});
            }
            else if(parent!=adjacentNode)
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