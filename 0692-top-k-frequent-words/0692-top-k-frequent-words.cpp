class comp{
  public:
       bool operator()(pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }

            return a.first < b.first;
        }
      };
    class Solution {
public:
        vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string , int> m;
        vector<string> ans;
        for(int i = 0; i < n; i++){
            m[words[i]]++;
        }
         vector<pair<int ,string>> p;
        for(auto & it : m){
         p.push_back(make_pair(it.second , it.first));
        }
        priority_queue<pair<int , string> , vector<pair<int , string>> , comp> pq(p.begin() , p.end());
        int i = 0;
        while(!pq.empty() && i < k){
         ans.push_back(pq.top().second);
         pq.pop();
         i++;
        }
        return ans;
    }
};
