class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int mnn = INT_MAX;
        int ans = 0;
        sort(nums.begin() , nums.end());
        for(int i = 0; i < n; i++){
           int st = i+1 , end = n-1;
           while(st < end){
            if(nums[i]+nums[st]+nums[end] == target){
                return nums[i]+nums[st]+nums[end];
            }else if(nums[i] +nums[st]+nums[end] > target){
                 int sum = nums[i]+nums[st]+nums[end];
                 if(abs(sum-target) < mnn){
                    mnn = abs(sum-target);
                    ans = sum;
                 }
                end--;
            }else if(nums[i] +nums[st]+nums[end] < target){
                 int sum = nums[i]+nums[st]+nums[end];
                 if(abs(sum-target) < mnn){
                    mnn = abs(sum-target);
                    ans = sum;
                 }
                st++;;
            }
           }
        }
        return ans;
    }
};