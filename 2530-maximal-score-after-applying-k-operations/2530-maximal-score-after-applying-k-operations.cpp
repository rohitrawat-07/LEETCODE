class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin() , nums.end());
        long long ans = 0;
        for(int i = 0; i < k; i++){
           int x = pq.top();
           ans += x;
           pq.pop();
           pq.push((x+2)/3);
        }
        return ans;
    }
};