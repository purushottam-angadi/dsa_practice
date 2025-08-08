#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<vector<int>> adj)
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(dfs(it,node,vis,adj))
        return true;
        else if(it!=parent)
        {
            return true;
        }

    }
    return false;
}
int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    // Creating a cyclic graph
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1); // This edge creates a cycle
    adj[1].push_back(4);

    int vis[]={0};
    bool hasCycle = false;

    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            if (dfs(i, -1, vis, adj)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "Cycle detected in the graph.\n";
    else
        cout << "No cycle found.\n";

    return 0;
}
