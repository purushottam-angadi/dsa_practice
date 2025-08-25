// class Solution {
//   public:
   
//     void dfs(int node, vector<vector<int>>& adj,vector<int>& vis, stack<int> &st)
//     {
//         vis[node]=1;
        
        
//         for(auto it : adj[node])
//         {
//             if(!vis[it])
//             {
//                 dfs(it,adj,vis,st);
//             }
//         }
//         st.push(node);
//     }
    
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         vector<int> vis(V,0);
//         stack<int> st;
//          vector<vector<int>> adj(V);
//         for (auto& edge : edges) {
//             adj[edge[0]].push_back(edge[1]);
//         }

//         for(int i=0; i<V; i++)
//         {
//             if(!vis[i])
//             {
//                 dfs(i,adj,vis,st);
//             }
//         }
//         vector<int> ans;
//         while(!st.empty())
//         {
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
// };