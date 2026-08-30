class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    }
    string arrangeWords(string text) {
        text.push_back(' ');
        int n = text.size();
        vector<string> ans;
        string x = "";
        for (int i = 0; i < n; i++) {
            if (text[i] != ' ') {
                x += text[i];
            } else {
                ans.push_back(x);
                x = "";
            }
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < ans.size(); i++) {
            auto x = ans[i].size();
            v.push_back({i, x});
        }

        sort(v.begin(), v.end(), cmp);
        string ans2 = "";
        for (auto& it : v) {
            if (it.first == 0) {
                ans[it.first][0] += 32;
            }
            ans2 += ans[it.first];
            ans2 += ' ';
        }
        ans2.pop_back();
        ans2[0] = ans2[0] - 32;

        return ans2;
    }
};