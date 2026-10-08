class Solution {
public:
    bool cycledetection(int src , vector<bool> & vis , vector<bool>& recpath , vector<vector<int>>& adj){
     
        vis[src] = true;
        recpath[src] = true;
        for(int v : adj[src]){
            if(!vis[v]){
                if(cycledetection(v , vis , recpath , adj)){
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
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size(); 
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i <  n; i++){
           int u = pre[i][0];
           int v = pre[i][1];
           adj[u].push_back(v);
        }

        vector<bool> vis( numCourses , false);
        vector<bool> recpath( numCourses , false);
        for(int i = 0; i <  numCourses; i++){
            if(!vis[i]){
                if(cycledetection(i , vis , recpath , adj)){
                    return false;
                }
            }
        }
        return true;
    }
};