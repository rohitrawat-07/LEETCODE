class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int minidx = 0;
        int maxidx = 0;
        int mxx = INT_MIN;
        int mnn = INT_MAX;
        for(int i = 0; i < n; i++){
         if(nums[i] > mxx){
            mxx = nums[i];
            maxidx = i;
         }
          if(nums[i] < mnn){
            mnn = nums[i];
            minidx = i;
         }
         
        }
        int x = min(minidx , maxidx);
        int y = max(minidx , maxidx);
           return min(x+1+n-y ,min(y+1 , n-x));   
    }
};