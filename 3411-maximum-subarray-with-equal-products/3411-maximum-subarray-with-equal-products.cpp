class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int mxx = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            int lc = nums[i];
            int gc = nums[i];
            long long int prod = nums[i];
            for (int j = i + 1; j < n; j++) {
                prod *= nums[j];
                lc = lcm(lc, nums[j]);
                gc = gcd(gc, nums[j]);
                if (prod == (long long)lc * gc) {
                    mxx = max(j - i + 1, mxx);
                }
                if(prod > 25200){
                    break;
                }
            }
        }
        return mxx;
    }
};