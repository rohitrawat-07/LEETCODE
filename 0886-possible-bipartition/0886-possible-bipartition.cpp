class Solution {
public:
  bool bfs(int x , vector<vector<int>>& graph , vector<int>& color){
      queue<int> q;
      q.push(x);
      color[x] = 0;
      while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i : graph[curr]){
            if(color[i] == -1){
                color[i] = !color[curr];
                q.push(i);
            }else{
                if(color[i] == color[curr]){
                    return false;
                }
            }
        }
      }
     return true;

   }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < dislikes.size(); i++){
           int u = dislikes[i][0];
           int v = dislikes[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);

        }
       vector<int> color(n+1 , -1);
       for (int i = 0; i < n; i++) {
         if (color[i] == -1) {
         if (!bfs(i, adj, color)) {
              return false;
              }
            }
        }
        return true;
    }
};