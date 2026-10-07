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
   
    bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
     vector<int> color(n , -1);
     for (int i = 0; i < n; i++) {
         if (color[i] == -1) {
         if (!bfs(i, graph, color)) {
              return false;
              }
            }
        }
        return true;

    }
};