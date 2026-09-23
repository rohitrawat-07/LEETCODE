class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<int , int>>p;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int x = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            p.push_back(make_pair(x , i));
        }
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq(p.begin(),p.end());
        int i = 0;
        while(!pq.empty() && i < k){
         ans.push_back({points[pq.top().second][0] , points[pq.top().second][1]});
         pq.pop();
         i++;
        }
      return ans;
    }
};