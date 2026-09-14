class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
         set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int st = i + 1, end = n - 1;
            while (st < end) {
                if (nums[i] + nums[st] + nums[end] == 0) {
                    s.insert({nums[i], nums[st], nums[end]});
                    st++;
                    end--;
                } else if (nums[i] + nums[st] + nums[end] > 0) {
                    end--;
                } else {
                    st++;
                }
            }
        }
       vector<vector<int>> ans(s.begin() , s.end());
       return ans;
    }
};