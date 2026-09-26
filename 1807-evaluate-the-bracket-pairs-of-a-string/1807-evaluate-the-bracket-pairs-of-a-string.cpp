class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string, string> m;
        for (int i = 0; i < knowledge.size(); i++) {
            m[knowledge[i][0]] = knowledge[i][1];
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            string temp = "";
            if (s[i] == '(') {
                i++;
                while (s[i] != ')') {
                    temp += s[i];
                    i++;
                }
              if(m.count(temp)){
                ans+=m[temp];
              }else{
                ans += '?';
              }
            }else{
                ans+= s[i];
            }
        }
            return ans;
        }
    };