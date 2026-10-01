class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 1) {
            return nums;
        }
        vector<int> ans(n, 0);
         int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] == 1) {
                count++;
            } else {
                count = 0;
            }

            ans[i + 1] = count;
        }
        vector<int> result;
        for (int i = k - 1; i < n; i++) {
            if (ans[i] >= k - 1) {
                result.push_back(nums[i]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};







