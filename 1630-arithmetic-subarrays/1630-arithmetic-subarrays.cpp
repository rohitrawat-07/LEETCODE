class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++){
            bool flag = true;
            vector<int> a;
          for(int j = l[i]; j <= r[i]; j++){
           a.push_back(nums[j]);
          } 
          sort(a.begin() , a.end());
          if(a.size() <= 2){
            ans.push_back(flag);
          
          }
          if(a.size() > 2){
            for(int i = 1; i < a.size()-1; i++){
            if(a[i]-a[i-1] != a[i+1]-a[i]){
                flag = false;
            }
          } 
          ans.push_back(flag);
          }
          
        }
        return ans;
    }
};