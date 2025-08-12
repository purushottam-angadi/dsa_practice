#include<iostream>
#include<vector>
using namespace std;



bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj,vector<int> &pathvis)
{
    vis[node]=1;
    pathvis[node]=1;

    for(auto it: adj[node])
    {
        if(!vis[it])
        {
           if(dfs(it,vis,adj, pathvis)==true) return true;
        }
        else if(vis[it]==1 && pathvis[it]==1 )
        {
           return true;
        }

    }
    pathvis[node]=0;
    return false;
}


int main()

{
     int nodes = 10;
    vector<vector<int>> adj(nodes + 1);

    adj[0] = {};
    adj[1] = {3};
    adj[2] = {4,7};
    adj[3] = {5};
    adj[4] = {6};
    adj[5] = {};
    adj[6] = {};
    adj[7] = {5};
    adj[8] = {9};
    adj[9] = {10};
    adj[10]={8};

    vector<int> vis(11,0);
    vector<int> pathvis(11,0);

     bool hasCycle = false;
    for (int i = 1; i <= nodes; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, adj, pathvis))
            {
                hasCycle = true;
                break;
            }
        }
    }

    cout << (hasCycle ? "Cycle detected" : "No cycle") << endl;
    return 0;
}
