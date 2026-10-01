class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int n = nums.size();
       unordered_map<int , int> m;
       int similar = 0;
       int count = 0;
       int j = 0;
       for(int i = 0; i < n; i++){
        m[nums[i]]++;
       while(j < i && (m[nums[j]] > 1 || m.size() > k)){
        if(m[nums[j]] > 1){
            similar++;
        }else{
            similar = 0;
        }
        m[nums[j]]--;
        if(m[nums[j]] == 0){
            m.erase(nums[j]);
        }
        j++;
       }
         if(m.size() == k){
            count += 1 + similar;
        }
       }
       return count;
    }
};