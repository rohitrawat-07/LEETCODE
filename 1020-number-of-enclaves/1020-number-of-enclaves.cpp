class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>& grid , vector<vector<bool>>& vis , int& sum){
       if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j] == true){
        return;
       }
         vis[i][j] = true;
         sum += grid[i][j];
        dfs(i , j+1 , grid , vis , sum);
        dfs(i , j-1 , grid , vis , sum);
        dfs(i+1, j , grid , vis , sum);
        dfs(i-1 , j , grid , vis , sum);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int sum = 0;
         vector<vector<bool>> vis(n , vector<bool>(m , false));
         for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                dfs(i , 0 , grid , vis , sum);
                sum = 0;
            }
            if(grid[i][m-1] == 1){
                 dfs(i , m-1 , grid , vis , sum);
                 sum = 0;
            }
         }
            for(int i = 0; i < m; i++){
            if(grid[0][i] == 1){
                dfs(0 , i , grid , vis , sum);
                sum = 0;
            }
            if(grid[n-1][i] == 1){
                 dfs(n-1 , i , grid , vis , sum);
                 sum = 0;
            }
         }
        for(int i = 0; i <n; i++){
            for(int j = 0; j < m; j++){
              if(grid[i][j] == 1){
                if(!vis[i][j]){
                    dfs(i , j , grid , vis , sum);      
                }
              }
            }
        }
        return sum;
    }
};