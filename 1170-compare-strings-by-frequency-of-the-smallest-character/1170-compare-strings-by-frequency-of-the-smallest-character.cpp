class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries,
                                      vector<string>& words) {
        int n = queries.size();
        vector<int> a;
        for (int i = 0; i < n; i++) {
            string s = queries[i];
            sort(s.begin(), s.end());
            char x = s[0];
            int count = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == x) {
                    count++;
                } else {
                    break;
                }
            }
            a.push_back(count);
        }
        vector<int> b;
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            sort(s.begin(), s.end());
            char x = s[0];
            int count = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == x) {
                    count++;
                } else {
                    break;
                }
            }
            b.push_back(count);
        }
         vector<int> ans;
        for(int i = 0; i < a.size(); i++){
            int count = 0;
            for(int j = 0; j < b.size(); j++){
              if(a[i] <  b[j]){
                count++;
              }
            }
            ans.push_back(count);
        }
        return ans;
    }
};