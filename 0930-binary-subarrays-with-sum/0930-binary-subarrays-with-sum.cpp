class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (m.count(sum - k)) {
                ans += m[sum - k];
            } 
            if(m.count(sum)){
                m[sum]++;
            }else{
                m[sum] = 1;
            }
        }
        return ans;
    }
};
















































































// class Solution {
// public:
//     int func(vector<int> & nums , int goal){
//     //     if(goal < 0){
//     //         return 0;
//     //     }
//     //      int n = nums.size();
//     //     int sum = 0;
//     //     int count = 0;
//     //     int j = 0;
//     //     for(int i = 0; i < n; i++){
//     //     sum += nums[i];
//     //     while(sum > goal){
//     //         sum -=nums[j];
//     //         j++;
//     //     }
//     //      count = count + (i-j+1);

//     //     }
//     //     return count;
//     // }
//     // int numSubarraysWithSum(vector<int>& nums, int goal) {
//     //   return func(nums , goal) - func(nums , goal-1);
//     }
// };