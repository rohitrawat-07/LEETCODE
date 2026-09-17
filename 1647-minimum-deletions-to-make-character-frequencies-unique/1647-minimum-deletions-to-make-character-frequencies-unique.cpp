
class Solution {
public:
    int minDeletions(string s) {
      unordered_map<char , int> m;
      vector<int> ans;
      int count = 0;
      for(int i = 0; i < s.size(); i++){
         m[s[i]]++;
      }
      for(auto & it: m){
        ans.push_back(it.second);
      }
     sort(ans.begin() , ans.end(), greater<int>());
      for(int i = 1; i < ans.size(); i++){
            while(ans[i] >= ans[i-1] && ans[i] != 0){
                ans[i]--;
                count++;
            
        }
      }
      return count;
    }
};