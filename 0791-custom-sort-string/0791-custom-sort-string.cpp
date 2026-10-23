class Solution {
public:
    string customSortString(string order, string s) {
     int n = order.size();
     unordered_map<char , int> m;
     for(int i = 0; i < s.size(); i++){
        m[s[i]]++;
     }
     string ans = "";
      for(int i = 0; i < n; i++){
        if(m.count(order[i])){
            for(int j = 0; j < m[order[i]]; j++){
                 ans += order[i];
            }
        }
        m.erase(order[i]);
      }
      string temp = "";
     for(auto & it :m){
        for(int i = 0; i < it.second; i++){
        temp += it.first;
        }
     }
     sort(temp.begin() , temp.end());
     return ans + temp;
    }
};