class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incr = 0;
        int decr = 0;
        int mxx = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n - 1; j++) { 
                if (nums[j] < nums[j + 1]) {
                    count++;
                } else {
                    count = 0;
                }
                mxx = max(count, mxx);
            }
        }

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n - 1; j++) { 
                if (nums[j] > nums[j + 1]) {
                    count++;
                } else {

                    count = 0;
                }
                mxx = max(count, mxx);
            }
        }
        if(mxx == INT_MIN){
            return 1;
        }
        return mxx + 1;
    }
};