class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<long long>> m;
        vector<long long> ans(n);
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }
       for(auto& el:m){
        
        int n = el.second.size();
        if(n == 1) {
        ans[el.second[0]] = 0;
        continue;
        }
      
        vector<long long> prefix(n);
        vector<long long> suffix(n);
      
        prefix[0] = el.second[0];
        suffix[n-1] = el.second[n-1];
       
        for(int i = 1; i < n; i++){ //.     for prefix;;;;
        prefix[i] = prefix[i-1] + el.second[i];
        }
      
        for(int i = n-2; i >=0; i--){          // for suffix;;;
            suffix[i] = suffix[i+1] + el.second[i];
        }
          
         ans[el.second[0]] = abs((el.second[0] * (n-1))- suffix[1]);
         ans[el.second[n-1]] = abs((el.second[n-1] * (n-1)) - prefix[n-2]);
       
         for(int i = 1; i < n-1; i++){
         long long a = abs((el.second[i] * i) - prefix[i-1]);
         long long b = abs((el.second[i] * (n-i-1)) - suffix[i+1]);
         ans[el.second[i]] = a+b;
  
         }
       }
       return ans;
    }
};