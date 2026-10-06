class Graph{
    int V;
    list<int>* l;
    public:
    Graph(int V){
     this->V = V;
     l = new list<int> [V];
    }
    void addEdge(int u , int v){
        l[u].push_back(v);   
    }
    
    void dfs(int u, vector<bool>& visited) {
    visited[u] = true;

    list<int> neighbour = l[u];

    for (int v : neighbour) {

        if (!visited[v]) {
            dfs(v, visited);
        }
    }
}
};
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        Graph graph(n);
        vector<bool> visited(n , false);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < rooms[i].size(); j++){
                graph.addEdge(i , rooms[i][j]);
            }
        }
         graph.dfs(0, visited);
       for(int i = 0; i < n; i++){
        if(!visited[i]){
            return false;
        }
       }
       return true;
    }
};