class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<bool>>& vis) {
        if (i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size() ||
            vis[i][j] == true || grid[i][j] == 1) {
            return;
        }
        vis[i][j] = true;
        dfs(i, j + 1, grid, vis);
        dfs(i, j - 1, grid, vis);
        dfs(i + 1, j, grid, vis);
        dfs(i - 1, j, grid, vis);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
               dfs(i , 0 , grid , vis);
            }
            if (grid[i][m - 1] == 0) {
                dfs(i , m-1 , grid , vis);
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) {
               dfs(0 , j , grid , vis);
            }
            if (grid[n - 1][j] == 0) {
                dfs(n-1 , j , grid , vis);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    if (!vis[i][j]) {
                        dfs(i, j, grid, vis);
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
