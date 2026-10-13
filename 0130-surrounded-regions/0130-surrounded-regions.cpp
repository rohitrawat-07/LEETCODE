class Solution {
public:
     void dfs(int i , int j , vector<vector<char>>& board , vector<vector<bool>>& vis){
       if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || vis[i][j] == true){
        return;
       }
         vis[i][j] = true;
        dfs(i , j+1 , board , vis);
        dfs(i , j-1 , board , vis);
        dfs(i+1 , j , board , vis);
        dfs(i-1 , j , board , vis);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
         vector<vector<bool>> vis(n , vector<bool>(m , false));
         for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                dfs(i , 0 , board , vis);
        
            }
            if(board[i][m-1] == 'O'){
                 dfs(i , m-1 , board , vis);
          
            }
         }
            for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                dfs(0 , i , board , vis);

            }
            if(board[n-1][i] == 'O'){
                 dfs(n-1 , i , board , vis);
               
            }
         }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
              if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
              }
            }
        }
    }
};

