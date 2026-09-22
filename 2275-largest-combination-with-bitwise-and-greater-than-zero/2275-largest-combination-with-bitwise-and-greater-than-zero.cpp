class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int n = nums.size();
        int mxx = INT_MIN;
        for (int i = 0; i < 24; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if ((nums[j] & (1 << i)) != 0) {
                    count++;
                }
            }
            mxx = max(count, mxx);
        }
        return mxx;
    }
};