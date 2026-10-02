class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxfreq = 0;
        int j = 0;
        int ans = 0;
        unordered_map<int , int> m;
       for(int i = 0; i < n; i++){
        m[s[i]]++;
       for(auto & it : m){
        maxfreq = max(maxfreq , it.second);  
       }
       while(j < i && i-j+1 - maxfreq > k){
        m[s[j]]--;
        if(m[s[j]] == 0){
            m.erase(s[j]);
        }
        j++;
       }

       if(i-j+1 - maxfreq <= k){
        ans = max(i-j+1 , ans);
       }
       }
       return ans;
    }
};