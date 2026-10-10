class Solution {
public:
    void func(int i , int j , int& count , int& mxx , vector<vector<int>>& grid , vector<vector<bool>>& vis){
     if(j < 0 || i < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j] == true){
        return;
     }
      vis[i][j] = true;
      count++;
     func(i , j+1 , count , mxx , grid , vis);
     func(i , j-1 , count , mxx , grid , vis);
     func(i+1 , j , count , mxx , grid , vis);
     func(i-1 , j , count, mxx , grid , vis);
     


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int mxx = 0;
        vector<vector<bool>> vis(n , vector<bool>(m , false));

       for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          if(grid[i][j] == 1){
            if(!vis[i][j]){
              func(i , j , count , mxx , grid , vis);
              mxx = max(count , mxx);
              count = 0;
            }
          }
        }
       }
       return mxx;
    }
};