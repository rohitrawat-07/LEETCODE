class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            ans.push_back(nums[i] - nums[i - 1]);
        }
        int count = 1;
        int result = 0;
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] == ans[i - 1]) {
                count++;
            } else {
                result += count * (count - 1)/2;
                count = 1;
            }
        }
        result += count * (count - 1) / 2;
        return result;
    }
};