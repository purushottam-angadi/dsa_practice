#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS starting from node 'start'
void bfs(int start, vector<vector<int>> adj, int n)
{
    vector<int> visited(n + 1, 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";

        for (auto it : adj[temp])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
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

    bfs(1, adj, nodes);
}