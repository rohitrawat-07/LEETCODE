class Solution {
public:
    int trailingZeroes(int n) {
       if(n < 5){
        return 0;
       }

        long long ans = 0;
       for(int i = 5; i <= n; i+=5){
           int original = i;
           long long count = 0;
           while(original % 5 == 0){
            original = original / 5;
            count++;
           }
           ans += count;
       }
       return ans;
    }
};