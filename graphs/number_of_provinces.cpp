#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS to explore fully connected components
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

// Returns number of provinces (connected components)
int provinces(vector<vector<int>> &adj, int n) {
    vector<int> vis(n, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int nodes = 10;
    vector<vector<int>> adj(nodes);

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

    int totalProvinces = provinces(adj, nodes);
    cout << "Number of provinces: " << totalProvinces << endl;

    return 0;
}