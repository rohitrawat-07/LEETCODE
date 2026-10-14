class Solution {
public:
       bool cycledetection(int src , vector<bool> & vis , vector<bool>& recpath , vector<vector<int>>& adj){
     
        vis[src] = true;
        recpath[src] = true;
        for(int v : adj[src]){
                if(!vis[v]){
                   if( cycledetection(v , vis , recpath , adj)){
                     return true;
                   }
                }else{
                    if(recpath[v]){
                        return true;
                    }
                }
        }
        recpath[src] = false;
        return false;

    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); 

        vector<int> ans;
        vector<bool> vis(n, false);
        vector<bool> recpath(n , false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(cycledetection(i , vis , recpath , graph)){
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(recpath[i] == false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};