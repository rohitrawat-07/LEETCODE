class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        long long sum = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            sort(grid[i].begin() , grid[i].end() , greater<int>());
            for(int j = 0; j < limits[i]; j++){
              ans.push_back(grid[i][j]);
            }
        }
        sort(ans.begin() , ans.end() , greater<int>());

        for(int i = 0; i < k ;i++){
            sum += ans[i];
        }
        return sum;
    }
};