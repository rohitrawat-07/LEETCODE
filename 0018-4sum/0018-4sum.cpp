class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        set<vector<int>> s;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int st = j+1 , end = n-1;
                while(st < end){
                  long long int sum = (long long)nums[i] + nums[j] + nums[st] + nums[end];
               if(sum == target){
                s.insert({nums[i] , nums[j] , nums[st] , nums[end]});
                st++;
                end--;
               }else if(sum < target){
                 st++;;
               }else{
                end--;
               }
                }
            }
        }
      vector<vector<int>> ans(s.begin() , s.end());
      return ans;
    }
};



