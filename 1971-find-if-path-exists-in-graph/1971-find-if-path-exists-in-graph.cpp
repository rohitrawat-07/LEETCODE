class Graph{
    int V;
    list<int>* l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }
    void add(int v , int u){
      l[v].push_back(u);
      l[u].push_back(v);
    }
    bool dfs(int source , int destination , vector<bool>&visited){
        if(source == destination){
            return true;
        }
        visited[source] = true;
        list<int> neighbour = l[source];
        for(int v : neighbour){
            if(!visited[v]){
                if(dfs(v , destination , visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        Graph graph(n);
           vector<bool> visited(n , false);
        for(int i = 0; i < edges.size(); i++){
         graph.add(edges[i][0] , edges[i][1]);
        }
        return graph.dfs(source , destination , visited);
    }
};