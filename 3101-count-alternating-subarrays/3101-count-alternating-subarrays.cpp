class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long count = 0;
        for(int i = 0; i < n-1; i++){
          if(nums[i] != nums[i+1]){
            count++;
          }else{
            ans += count * (count+1)/2;
            count = 0;
          }

        }
         ans += count * (count+1)/2;
        return ans + n;
    }
};