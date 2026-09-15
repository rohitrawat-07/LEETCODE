class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                idx = i-1;
                break;
            }
        }
       long long int sum1 = 0;
       long long int sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (i <= idx) {
                sum1 += nums[i];
            }
            if (i >= idx) {
                sum2 += nums[i];
            }
        }
            if(sum1 > sum2){
                return 0;
            }
            if(sum2 > sum1){
                return 1;
            }
           
        return -1;
        }
    };