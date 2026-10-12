class Solution {
public:
    bool dfs( vector<vector<int>>& adj , int source, int destination , vector<bool> & vis){
      if(source == destination){
        return true;
      }
      vis[source] = true;
      for(int v : adj[source]){
        if(!vis[v]){
          if(dfs(adj , v , destination , vis)){
              return true;
          }
        }
      }
      return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n , false);
        for(int i = 0; i < edges.size(); i++){
          int u = edges[i][0];
          int v = edges[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
     return dfs(adj , source , destination , vis);
    }
};