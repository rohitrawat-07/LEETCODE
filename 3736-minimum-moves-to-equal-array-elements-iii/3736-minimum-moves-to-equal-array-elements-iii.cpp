class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mxx = INT_MIN;
        for(int i = 0; i < n; i++){
            mxx = max(nums[i] , mxx);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += mxx-nums[i];
        }
        return sum;
    }
};