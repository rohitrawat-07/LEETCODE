class Solution {
public:
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& vis, int& count) {
        vis[u] = true;
        count++;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(adj, v, vis , count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        int count = 0;
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         vector<bool> vis(n, false);
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    dfs(adj, i, vis, count);
                    ans.push_back(count);
                    count = 0;
                }
            }
    

        
        vector<long long> sum(ans.size());
        long long int x = 0;
        for(int i = ans.size()-1; i >= 0; i--){
           x += ans[i];
           sum[i] = x;
        }
        long long int result = 0;
        for(int i = 1; i < ans.size(); i++){
         result += ans[i-1] * sum[i];
        }
        return result;
    } 
};