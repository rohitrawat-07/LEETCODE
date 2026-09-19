class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
      int n = nums.size();
      vector<int> prefix(n);
      vector<int> suffix(n);
      prefix[0] = nums[0];
      suffix[n-1] = nums[n-1];
      for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + nums[i];
      } 
      for(int i = n-2; i >= 0; i--){
        suffix[i] = nums[i]+suffix[i+1];
      }
     vector<int> ans(n);
     ans[n-1] = abs((nums[n-1] * (n-1)) - prefix[n-2]);
     ans[0] = abs((nums[0] * (n-1))- suffix[1]);
     for(int i = 1; i < n-1; i++){
      int a = abs((nums[i] * i) - prefix[i-1]);
      int b = abs((nums[i] * (n-i-1)) - suffix[i+1]);
      ans[i] = a+b;
     }
     return ans;
    }
};