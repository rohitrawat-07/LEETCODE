class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<char> chars;
        for (int i = 0; i < n; i++) {
            chars.push_back(s[i]);
        }

        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;
        vector<char> ans(n, '1');
        for (int i = 0; i < n; i++) {
            m[chars[i]]++;
        }
        vector<pair<int, char>> p;
        for (auto& it : m) {
            pq.push({it.second, it.first});
        }
        for (int i = 0; i < n; i += 2) {
            char x = pq.top().second;
            ans[i] = x;
            m[x]--;
            if (m[x] == 0) {
                pq.pop();
            }
        }
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] == '1') {
                char x = pq.top().second;
                ans[i] = x;
                m[x]--;
                if (m[x] == 0) {
                    pq.pop();
                }
            }
        }
        string OrganisedString = "";
        OrganisedString += ans[0];
        for (int i = 1; i < n; i++) {
            if (ans[i] != ans[i - 1]) {
            OrganisedString += ans[i];

            }else{
                return "";
            }
        }

        return OrganisedString;
    }
};