class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>& grid , vector<vector<bool>>& vis , long long& sum){
    if(i < 0 || j < 0|| i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j] == true){
        return;
    }
      vis[i][j] = true;
      sum += grid[i][j];
     dfs(i , j+1 , grid , vis , sum);
     dfs(i , j-1 , grid , vis , sum);
     dfs(i+1, j , grid , vis , sum);
     dfs(i-1 , j , grid , vis , sum);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        long long sum = 0;
        long long mxx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    if(!vis[i][j]){
                    dfs(i , j , grid , vis , sum);
                    mxx = max(sum , mxx);
                      sum = 0;
                    
                }
            }
        }
        }
        return mxx;
    }
};




