class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
       
        vector<pair<int , int>> p;
        for(int i = 0; i < n; i++){
            p.push_back(make_pair(score[i] , i));
        }
         priority_queue<pair<int , int>> pq(p.begin() , p.end());
         int i = 0;
          ans[pq.top().second] = "Gold Medal";
          pq.pop();
          if(pq.empty()) return ans;
          ans[pq.top().second] = "Silver Medal";
          pq.pop();
             if(pq.empty()) return ans;
          ans[pq.top().second] = "Bronze Medal";
          pq.pop();
             if(pq.empty()) return ans;
          int x = 4;
          while(!pq.empty()){
            ans[pq.top().second] = to_string(x);
            pq.pop();
            x++;
          }
          return ans;
    }
};