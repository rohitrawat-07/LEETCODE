class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int rowIdx = 0;
        int colIdx = 0;
        int i = 0;
        int j = 0;
        int m = grid[0].size();
        while (i < n && j >= 0) {
            rowIdx = i;
            colIdx = j;
            if (grid[i][j] == 'R') {
                grid[i][j] = 'V';
                j = j + 1;
            } else if (grid[i][j] == 'L') {
                grid[i][j] = 'V';
                j = j-1;
            } else if (grid[i][j] == 'U') {
                grid[i][j] = 'V';
                i = i-1;
            } else if (grid[i][j] == 'D') {
                grid[i][j] = 'V';
                i = i+1;
            }
            if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 'V'){
                return {rowIdx , colIdx};
            }
        }
        return {n-1 , m-1};
    }
};