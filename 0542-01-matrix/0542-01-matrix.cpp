class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> result(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        int drow[] = {0, 1, -1, 0};
        int dcol[] = {1, 0, 0, -1};
        while (!q.empty()) {
            int st = q.front().first;
            int end = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int a = st + drow[i];
                int b = end + dcol[i];
                if (a >= 0 && a < n && b >= 0 && b < m && result[a][b] == -1) {
                    result[a][b] = result[st][end] + 1;
                    q.push(make_pair(a, b));
                }
            }
        }
        return result;
    }
};