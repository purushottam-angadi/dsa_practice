
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS starting from node 'start'
void bfs(int node, vector<vector<int>> adj, int vis[])
{
   vis[node]=1;
   cout<< node<<" ";
   for(auto it : adj[node])
   {
     if(!vis[it])

     {
           bfs(it, adj, vis);
     }
   }
}

int main()
{
    int nodes = 9;
    vector<vector<int>> adj(nodes + 1);

    adj[0] = {};
    adj[1] = {2, 6};
    adj[2] = {1, 3, 4};
    adj[3] = {2};
    adj[4] = {2, 5};
    adj[5] = {4, 8};
    adj[6] = {1, 7, 9};
    adj[7] = {6, 8};
    adj[8] = {5, 7};
    adj[9] = {6};
    int vis[nodes+1]={0};
   bfs(1,adj,vis);
    
}