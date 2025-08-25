// class Solution {
// public:
//     vector<int> shortestPath(vector<vector<int>>& adj, int src) {
//         int n = adj.size();
//         vector<int> dis(n, 1e9);  // Initialize distances to "infinity"
//         queue<int> q;

//         dis[src] = 0;
//         q.push(src);

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             for (auto it : adj[node]) {
//                 if (dis[it] > dis[node] + 1) {
//                     dis[it] = dis[node] + 1;
//                     q.push(it);
//                 }
//             }
//         }

//         // Replace unreachable distances with -1
//         for (int i = 0; i < n; ++i) {
//             if (dis[i] == 1e9) dis[i] = -1;
//         }

//         return dis;
//     }
// };