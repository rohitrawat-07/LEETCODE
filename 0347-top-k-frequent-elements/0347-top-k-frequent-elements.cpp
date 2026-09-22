class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> m;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        priority_queue<pair<int , int>> pq;
        for (auto it = m.begin(); it != m.end(); it++) {
         pq.push({it->second, it->first});
       }
     for(int i = 0; i < k; i++){
        ans.push_back(pq.top().second);
        pq.pop();
     }
     return ans;
    }
};