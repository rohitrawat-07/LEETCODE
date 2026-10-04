class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;
        int rowCount = 0;
        while (i < n) {
            int st = 0;
            int end = m - 1;
            while (st < end) {
                if (grid[i][st] != grid[i][end]) {
                    rowCount++;
                }
                st++;
                end--;
            }
            i++;
        }
        int columnCount = 0;
        int j = 0;
        while (j < m) {
            int st = 0;
            int end = n - 1;
            while (st < end) {
                if (grid[st][j] != grid[end][j]) {
                    columnCount++;
                }
                st++;
                end--;
            }
            j++;
        }

        return min(rowCount, columnCount);
    }
};