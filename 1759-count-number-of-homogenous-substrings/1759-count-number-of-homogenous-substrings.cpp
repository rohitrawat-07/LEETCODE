class Solution {
public:
    int countHomogenous(string s) {
        long long count = 1;
        int n = s.size();
        long long ans = 0; 
        for(int i = 1; i < n; i++){
         if(s[i] == s[i-1]){
            count++;
         }else{
            ans += count * (count+1)/2;
            ans = ans%1000000007;
            count = 1;
         }
        }
        ans += count * (count+1)/2 ;
        return ans % 1000000007;
    }
};