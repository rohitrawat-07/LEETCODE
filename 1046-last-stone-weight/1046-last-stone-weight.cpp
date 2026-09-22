class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0){
            return 0;
        }
        priority_queue<int> pq(stones.begin() , stones.end());
        if(pq.size() == 1){
            return pq.top();
        }
         while(!pq.empty() && pq.size() != 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x > y){
                pq.push(x-y);
            }
            if(y > x){
                pq.push(y-x);
            }
            
         }
          if(pq.empty()) return 0;
          return pq.top();
    }
};