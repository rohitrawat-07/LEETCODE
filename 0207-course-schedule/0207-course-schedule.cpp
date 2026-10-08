class Solution {
public:
    bool cycledetection(int src , vector<bool> & vis , vector<bool>& recpath , vector<vector<int>>& adj){
     
        vis[src] = true;
        recpath[src] = true;
        for(int i = 0; i < adj.size(); i++){
            int u = adj[i][1];
            int v = adj[i][0];
            if(u == src){
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
        }
        recpath[src] = false;
        return false;

    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size(); 
        vector<bool> vis( numCourses , false);
        vector<bool> recpath( numCourses , false);
        for(int i = 0; i <  numCourses; i++){
            if(!vis[i]){
                if(cycledetection(i , vis , recpath , pre)){
                    return false;
                }
            }
        }
        return true;
    }
};