class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int rem = 9;
        int original = sum;
       for(int i = 0; i < num;i++){
         if(sum <= 9){
           ans += sum + '0';
            sum -= sum;
         }
         if(sum > 9){
           ans += rem + '0';
           sum = sum-rem;
         }
       }
       int mySum = 0;
       for(int i = 0; i < ans.size(); i++){
        mySum += ans[i]-'0';

       }
       if(mySum != original){
        return "";
       }
       return ans;
    }
};