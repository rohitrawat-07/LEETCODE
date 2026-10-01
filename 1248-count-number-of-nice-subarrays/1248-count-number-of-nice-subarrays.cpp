class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> m;
        m[0] = 1;
        int count = 0, sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(m.count(sum-k)){
                count += m[sum-k];
            }
            if(m[sum] == 0){
                m[sum] = 1;
            }else{
                m[sum]++;
            }
        }
        return count;
    }
};









