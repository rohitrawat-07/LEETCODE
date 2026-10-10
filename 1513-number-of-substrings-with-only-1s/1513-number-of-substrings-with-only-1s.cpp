class Solution {
public:
    int numSub(string s) {
       int n = s.size();
       long long ans = 0;
       long long count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                count++;
            }
            if(s[i] == '0'){
            ans += (count * (count+1))/2;
            ans = ans % 1000000007;
                count = 0;
            }

  
        }
        ans += count * (count+1)/2 ;
        return ans % 1000000007;
    }
};