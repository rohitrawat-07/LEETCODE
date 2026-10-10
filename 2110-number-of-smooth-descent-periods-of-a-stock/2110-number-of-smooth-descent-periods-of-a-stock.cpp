class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n = nums.size();
        long long count = 1;
        long long ans = 0;
        for(int i = 1; i < n; i++){
          if(nums[i] == nums[i-1]-1){
            count++;
          }else{
            ans += count * (count+1)/2;
            count = 1;
          }
        }
        ans += count * (count+1)/2;
        return ans;
    }
};




