class info{
    public:
    int u;
    int cost;
    int stops;
        info(int u, int cost, int stops) {
        this->u = u;
        this->cost = cost;
        this->stops = stops;
    }

};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<info> q;
        vector<int> dist(n+1 , INT_MAX);
        dist[src] = 0;
        q.push(info(src , 0 , -1));

        while(q.size() > 0){
            info curr = q.front();
            q.pop();

            for(int i = 0; i < flights.size(); i++){
                if(flights[i][0] == curr.u){
                    int v = flights[i][1];
                    int wt = flights[i][2];

                  if(dist[v] > wt + curr.cost && curr.stops+1 <= k){
                    dist[v] = wt + curr.cost;
                    q.push(info(v , dist[v] , curr.stops+1));
                  }  
                }
            }
        }
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};