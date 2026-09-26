class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> s;
        sentence += " ";
        string temp = "";
        for (int i = 0; i < sentence.size(); i++) {
          if (sentence[i] == ' ') {
          s.push_back(temp);
          temp = "";
          }
          else {
          temp += sentence[i];
          }
        }

        unordered_map<string, int> m;
        for (int i = 0; i < dictionary.size(); i++) {
            m[dictionary[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            string temp = "";
            for (int j = 0; j < s[i].size(); j++) {
                temp += s[i][j];
                if (m.count(temp)) {
                    s[i] = temp;
                    break;
                }
            }
            
          
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            ans += s[i];
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};
