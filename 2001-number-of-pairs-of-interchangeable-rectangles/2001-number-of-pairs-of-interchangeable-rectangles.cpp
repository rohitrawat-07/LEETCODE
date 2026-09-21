class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rect) {
        int n = rect.size();
        unordered_map<double , int> m;
      for(int i = 0; i < n; i++){
       double x = rect[i][0]/(double)rect[i][1];
        m[x]++;
      }
      long long int count = 0;
      for(auto & it:m){
        long long int x = it.second;
        count += x*(x-1)/2;
      }
      return count;
    }
};