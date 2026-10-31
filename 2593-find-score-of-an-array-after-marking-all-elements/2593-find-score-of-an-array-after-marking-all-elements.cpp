class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> p;
        vector<bool> vis(n, false);
        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            p.push_back(make_pair(nums[i], i));
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < n; i++) {
            int idx = p[i].second;
            if (vis[idx] == false) {
                sum += p[i].first;
                vis[idx] = true;
                if (idx - 1 >= 0) {
                    vis[idx - 1] = true;
                }
                if (idx + 1 < n) {
                    vis[idx + 1] = true;
                }
            }
        }
        return sum;
    }
};