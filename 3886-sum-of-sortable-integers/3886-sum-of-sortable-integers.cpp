class Solution {
public:
    bool func(vector<int>& nums, int n) {
        int mxx = INT_MIN;
        for (int i = 0; i < nums.size(); i += n) {
            int count = 0;
            int mnn = INT_MAX;
          for(int j = i; j < n+i-1; j++){
            if(nums[j] > nums[j+1]){
                count++;
            }
          }
          if (nums[i + n - 1] > nums[i]) {
             count++;
           }
          if(count > 1){
            return false;
          }
          for(int j = i; j < n+i; j++){
            mnn = min(nums[j] , mnn);
          }
          if(mxx > mnn){
            return false;
          }
           for(int j = i; j < n+i; j++){
            mxx = max(nums[j] , mxx);
          }
    }
     return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> divs;
        for (int i = 1; i <= nums.size(); i++) {
            if (n % i == 0) {
                divs.push_back(i);
            }
        }
         int ans = 0;
        for(int i = 0; i < divs.size(); i++){
            if(func(nums , divs[i])){

                ans += divs[i];
            }
        }
        return ans;
    }
};