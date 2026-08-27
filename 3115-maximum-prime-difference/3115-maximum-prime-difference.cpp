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
    int maximumPrimeDifference(vector<int>& nums) {
        int first = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
        if(isPrime(nums[i])){
            first = i;
            break;
           }
        }
        int second = 0;
        for(int i = n-1; i >= 0; i--){
            if(isPrime(nums[i])){
                second = i;
                break;
            }
        }
        return second - first;
    }
};

