class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        unordered_map<char , vector<long long>> m;
        for(int i = 0; i < n; i++){
         m[s[i]].push_back(cost[i]);
        }
       for(auto& it : m){
        for(int i = 1; i < it.second.size(); i++){
         it.second[0] += it.second[i];
        }
       }
       vector<pair<long long , char>> p;
       for(auto & it : m){
        p.push_back(make_pair(it.second[0] , it.first));
       }
       long long ans = 0;
       sort(p.begin() , p.end());
      for(int i = 0; i < p.size(); i++){
        if(p[i].second != p[p.size()-1].second){
            ans += p[i].first;
        }
      }
      return ans;
    }
};