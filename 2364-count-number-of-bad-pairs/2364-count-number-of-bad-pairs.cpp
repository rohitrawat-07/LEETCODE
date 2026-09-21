class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
       unordered_map<int , int> m;
       for(int i = 0; i < n; i++){
         m[nums[i]-i]++;
       }
      long long int count = 0;
       for(auto& it:m){
        int x = it.second;
        count += ((long long)x * (long long)(x-1))/2;
       }
      long long int allPairs = ((long long)n*(long long)(n-1))/2;
      return allPairs - count;
    }
};