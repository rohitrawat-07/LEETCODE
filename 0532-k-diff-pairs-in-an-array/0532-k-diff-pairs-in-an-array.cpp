class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> m;
        set<pair<int, int>> s2;

      for(int i = 0; i < n; i++){
        m[nums[i]] = i;
      }
    for(int i = 0; i < n; i++){
        int b = nums[i]-k;
        if(m.count(b) && i != m[b]){
            if(b <= nums[i]){
                s2.insert(make_pair(b , nums[i]));
            }else{
                s2.insert(make_pair(nums[i] , b));
            }
            
        }
        int c = nums[i]+k;
        if(m.count(c) && i != m[c]){
            if(c <= nums[i]){
                s2.insert(make_pair(c , nums[i]));
            }else{
                s2.insert(make_pair(nums[i] , c));
            }
            
        }
    }
     return s2.size();
    }
};