class Solution {
public:
     void topoSort(int src , vector<bool>& vis , stack<int>& s , vector<vector<int>>& graph){
        vis[src] = true;
      for(int i = 0; i < graph.size(); i++){
            int u = graph[i][1];
            int v = graph[i][0];
            if(u == src){
                if(!vis[v]){
                    topoSort(v , vis, s , graph);
                   }
                
            }
        }
        s.push(src);

     }
      bool checkCycle(int src , vector<bool>& vis , vector<bool>& recPath,vector<vector<int>>& graph){
        vis[src] = true;
        recPath[src] = true;
        for(int i = 0; i < graph.size(); i++){
            int u = graph[i][1];
            int v = graph[i][0];
            if(u == src){
                if(!vis[v]){
                   if(checkCycle(v , vis , recPath , graph)){
                     return true;
                   }
                }else{
                    if(recPath[v]){
                        return true;
                    }
                }
            }
        }
        recPath[src] = false;
        return false;

    }
       vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(numCourses , false);
        vector<bool> recPath(numCourses , false);
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(checkCycle(i , vis , recPath , graph)){
                    return {};
                }
            }
        }
         vector<bool> viss(numCourses , false);
         stack<int> s;
        for(int i = 0; i < numCourses; i++){
           if(!viss[i]){
            topoSort(i ,viss , s , graph);
           }
        }
         vector<int> ans;
        while(!s.empty()){
          ans.push_back(s.top());
          s.pop();
        }
        return ans;
    }
};

