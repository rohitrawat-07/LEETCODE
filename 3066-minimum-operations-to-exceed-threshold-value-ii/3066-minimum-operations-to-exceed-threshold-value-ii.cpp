class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long , vector<long long> , greater<long long>> pq(nums.begin() , nums.end());
        int count = 0;
        while(pq.size() >= 2 && pq.top() < k){
            long long min1 = pq.top();
            pq.pop();
            long long min2 = pq.top();
            pq.pop();
            pq.push((min(min1 , min2) * 2) + max(min1 , min2));
            count++;
        }
        return count;
    }
};