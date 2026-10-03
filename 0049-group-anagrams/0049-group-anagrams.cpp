class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      int n = strs.size();
       vector<string> x(strs.begin() , strs.end());
      unordered_map<string , vector<int>> m;
        for(int i = 0; i < n; i++){
            sort(x[i].begin() , x[i].end());
            m[x[i]].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto& it : m){
            vector<string> vec;
            for(int i = 0; i < it.second.size(); i++){
             vec.push_back(strs[it.second[i]]);
            }
            ans.push_back(vec);
        }
        return ans;
      }
};