class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int , int> m;
        for(int i = 0; i < n; i++){
            m[arr[i]]++;
        }
       vector<int> p;
       for(auto& it : m){
        p.push_back(it.second);
       }
       int count = 0;
       int ans = 0;
       priority_queue<int> pq(p.begin() , p.end());
       while(!pq.empty() && count < n/2){
        count+=pq.top();
        ans++;
        pq.pop();
       }
       return ans;
    }
};