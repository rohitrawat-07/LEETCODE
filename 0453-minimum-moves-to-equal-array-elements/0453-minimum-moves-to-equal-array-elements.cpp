class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int Min = INT_MAX;
        int sum = 0;
        for(int i = 0; i < n;i++){
            Min = min(nums[i] , Min);
        }

        for(int i = 0; i < n; i++){
       sum+= nums[i] - Min;
        }
        return sum;
    }
};