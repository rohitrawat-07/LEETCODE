class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        set<int> s;
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        int a = lower;
        while (a <= upper) {
            if (s.find(a) != s.end()) {
                if (lower < a) {
                    ans.push_back({lower, a - 1});
                }
                lower = a + 1;
            }

            a++;
        }
        if (lower <= upper) {
            ans.push_back({lower, upper});
        }
        return ans;
    }
};
