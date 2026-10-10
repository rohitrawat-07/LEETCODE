class Solution {
public:
    void dfs(int i , int j , vector<vector<char>>& grid , vector<vector<bool>>& vis){
        if(j < 0 || i < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] == true || grid[i][j] == '0'){
            return;
        }
        vis[i][j] = true;
        dfs(i+1 , j , grid , vis);
        dfs(i-1 , j , grid , vis);
        dfs(i , j+1 , grid , vis);
        dfs(i , j-1 , grid , vis);
    }
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<bool>> vis(n , vector<bool>(m , false));
       int count = 0;
       for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                if(!vis[i][j]){
                    dfs(i , j , grid , vis);
                    count++;
                }
            }
        }
        
       }
       return count;
    }
};