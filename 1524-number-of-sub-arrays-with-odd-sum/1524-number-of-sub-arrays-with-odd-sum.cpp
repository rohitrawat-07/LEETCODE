class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int mod = 1e9 + 7;

        int even = 1;
        int odd = 0;

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            if (sum % 2 != 0) {
                count = (count + even) % mod;
                odd++;
            }
            else {
                count = (count + odd) % mod;
                even++;
            }
        }

        return count;
    }
};