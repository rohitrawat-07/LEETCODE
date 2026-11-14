class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m = 1e9+7;
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back(make_pair(v, wt));
            adj[v].push_back(make_pair(u, wt));
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> countPath(n , 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        dist[0] = 0;
        pq.push(make_pair(0, 0));
        countPath[0] = 1;
        while (!pq.empty()) {
            int u = pq.top().second;
             long long d = pq.top().first;
            pq.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                 long long wt = adj[u][i].second;

                if (dist[v] > d + wt) {
                    dist[v] = d + wt;
                    pq.push(make_pair(dist[v], v));
                    countPath[v] = countPath[u];
                }else if(dist[v] == d + wt){
                    countPath[v] = (countPath[v] + countPath[u]) % m;
                }
            }
        }
         return countPath[n-1];
    }
};