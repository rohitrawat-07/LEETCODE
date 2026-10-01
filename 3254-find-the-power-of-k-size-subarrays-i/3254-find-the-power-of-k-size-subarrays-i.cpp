class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
       int n = nums.size();
      vector<int> ans;
      bool isChecked = false;
      for(int i = 0; i <= n-k; i++){
        int count = 1;
        bool isChecked = false;
        for(int j = i; j < i+k-1; j++){
         if(nums[j+1] - nums[j] > 1 || nums[j+1]-nums[j] <= 0){
            ans.push_back(-1);
            isChecked = true;
            break;
              }else{
                count += nums[j+1]-nums[j];
              }
        }
        if(isChecked == false){
        if(count == k){
            ans.push_back(nums[i+k-1]);
        }else{
            ans.push_back(-1);
        }
        }
      }
      return ans;
    }
};

