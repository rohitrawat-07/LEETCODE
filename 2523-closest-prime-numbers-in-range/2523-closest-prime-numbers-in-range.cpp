class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans;
        int minidx = 0;
        int min = INT_MAX;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                ans.push_back(i);
            }
        }
        if(ans.size() < 2){
            return {-1 , -1};
        }
        if(ans.size() == 2){
            return {ans[0] , ans[1]};
        }
        for (int i = 1; i < ans.size(); i++) { 
           if(ans[i] - ans[i - 1] < min){  
            min = ans[i] - ans[i - 1];
            minidx = i-1;
           }
        }
    
    
    return {ans[minidx], ans[minidx + 1]};
}
};
