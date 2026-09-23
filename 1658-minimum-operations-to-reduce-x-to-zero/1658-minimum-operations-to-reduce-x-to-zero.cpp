class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int n = nums.size();
      int a = 0;
      for(int i = 0; i < n; i++){
          a += nums[i];
      }
      int k = a - x;
      int sum = 0;
      int j = 0;
      int mxx = INT_MIN;
      for(int i = 0; i < n; i++){
       sum += nums[i];
       while(sum > k && j <= i){
        sum -= nums[j];
        j++;
       }
        if(sum == k){
        mxx = max(i-j+1 , mxx);
       }
      }
      if(mxx == INT_MIN){
        return -1;
      }
      return n-mxx;
}
};
