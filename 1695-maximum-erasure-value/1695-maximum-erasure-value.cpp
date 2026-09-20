class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       int n = nums.size();
       int sum = 0;
       int j = 0;
       int maxSum = 0;
       unordered_map<int , int> m;
       for(int i = 0; i < n; i++){
           sum += nums[i];
           m[nums[i]]++;
            while(m[nums[i]] > 1){
                sum -= nums[j];
                m[nums[j]]--;
                if(m[nums[j]] == 0){
                    m.erase(nums[j]);
                }
                j++;
            }
        maxSum = max(sum , maxSum);
         
       }
       return maxSum;
    }
};
