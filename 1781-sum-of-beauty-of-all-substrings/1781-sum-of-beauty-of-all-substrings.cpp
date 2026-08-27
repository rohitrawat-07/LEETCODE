class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> m;
            for (int j = i; j < n; j++) {
                m[s[j]]++;
                if (m.size() == 1) {
                    continue;
                } else {
                    int maxfreq = INT_MIN;
                    int minfreq = INT_MAX;
                    for (auto& el : m) {
                        if (el.second > maxfreq) {
                            maxfreq = el.second;
                        }
                        if (el.second < minfreq) {
                            minfreq = el.second;
                        }
                    }
                    ans += maxfreq - minfreq;
                }
            }
        }
        return ans;
    }
};