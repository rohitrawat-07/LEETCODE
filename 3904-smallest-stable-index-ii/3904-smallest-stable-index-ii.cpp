class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        int mnn = INT_MAX;
       for(int i = n-1; i >= 0; i--){
         mnn = min(mnn , nums[i]);
         ans[i] = mnn;
       }
        int idx = -1;
        int mxx = INT_MIN;
       for(int i = 0; i < n; i++){
        mxx = max(nums[i] , mxx);
         if(mxx - ans[i] <= k){
            idx = i;
             break;
         }
       }
       return idx;
    }
};