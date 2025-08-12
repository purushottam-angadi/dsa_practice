class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({r, c});
        vis[r][c] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (!vis[r][c] && grid[r][c] == '1') {
                    bfs(r, c, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};