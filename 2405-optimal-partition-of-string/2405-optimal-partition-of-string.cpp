class Solution {
public:
    int partitionString(string s) {
      int n = s.size();
      unordered_map<char , int> m;
      int ans = 0;
      for(int i = 0; i < n; i++){
        m[s[i]]++;
        if(m[s[i]] > 1){
            m.clear();
            ans++;
            m[s[i]]++;
        }
      }
      if(m[s[n-1]] == 1){
        ans++;
      }
      return ans;
    }
};