class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        int leftmax = -1;
        for(int i = 0; i < n; i++){
           int rightmin = INT_MAX;
            leftmax = max(leftmax , nums[i]);
            for(int j = i; j < n; j++){
             rightmin = min(rightmin , nums[j]);
            }
            if(leftmax - rightmin <= k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};