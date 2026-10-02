class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
       int Min = INT_MAX;
       int sum = 0;
       int j = 0;
       for(int i = 0; i < n; i++){
           sum += nums[i];

          while(sum > target){
            Min = min(i-j+1 , Min);
            sum -= nums[j];
            j++;
          }

           if(sum == target){
            Min = min(i-j+1 , Min); 
           }
       }
       if(Min == INT_MAX){
        return 0;
       }
       return Min;
    }
};