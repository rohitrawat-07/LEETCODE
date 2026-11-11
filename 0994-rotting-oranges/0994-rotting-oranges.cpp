class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n, (vector<bool>(m, false)));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    vis[i][j] = true;
                    count++;
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int x = count;
            count = 0;
            for (int i = 0; i < x; i++) {
                int f = q.front().first;
                int s = q.front().second;
                q.pop();
                if (f + 1 < n && !vis[f + 1][s] && grid[f + 1][s] == 1) {
                    vis[f + 1][s] = true;
                    grid[f + 1][s] = 2;
                    q.push(make_pair(f + 1, s));
                    count++;
                }
                if (f - 1 >= 0 && !vis[f - 1][s] && grid[f - 1][s] == 1) {
                    vis[f - 1][s] = true;
                    grid[f - 1][s] = 2;
                    q.push(make_pair(f - 1, s));
                    count++;
                }
                if (s + 1 < m && !vis[f][s + 1] && grid[f][s + 1] == 1) {
                    vis[f][s + 1] = true;
                    grid[f][s+1] = 2;
                    q.push(make_pair(f, s + 1));
                    count++;
                }
                if (s - 1 >= 0 && !vis[f][s - 1] && grid[f][s - 1] == 1) {
                    vis[f][s - 1] = true;
                    grid[f][s-1] = 2;
                    q.push(make_pair(f, s - 1));
                    count++;
                }
            }
            cout << count;
            if (count > 0) {
                ans++;
            }
        }
       
            for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                   return -1;
                }
            }
        }
        return ans;
    }
};