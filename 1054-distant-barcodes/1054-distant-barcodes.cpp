class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
     int n = barcodes.size();
     unordered_map<int , int> m;
     priority_queue<pair<int, int>> pq;    
     vector<int> ans(n , -1);
       for(int i = 0; i < n; i++){
        m[barcodes[i]]++;
       } 
       vector<pair<int , int>> p;
       for(auto & it: m){
        pq.push({it.second , it.first});
       }
      for(int i = 0; i < n; i+=2){
        int x = pq.top().second;
        ans[i] = x;
        m[x]--;
        if( m[x] == 0){
            pq.pop();
        }
      }
        for(int i = 1; i < n; i++){
            if(ans[i] == -1){
                  int x = pq.top().second;
                  ans[i] = x;
                  m[x]--;
                  if(m[x] == 0){
                    pq.pop();
                  }
            }
        
     }
     return ans;
    }

};