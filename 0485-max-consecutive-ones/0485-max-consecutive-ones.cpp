class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mxx = -1;
         for(int i = 0; i < n;i++){
          sum += nums[i];
          mxx = max(sum , mxx);
           if(nums[i] == 0){
            sum = 0;
           }
         }
         return mxx;
       
    }
};