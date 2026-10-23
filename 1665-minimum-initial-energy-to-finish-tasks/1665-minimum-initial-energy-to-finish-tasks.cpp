class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
     return abs(a[1] - a[0]) > abs(b[1] - b[0]);
}

    int minimumEffort(vector<vector<int>>& tasks) {
      int n = tasks.size();
      sort(tasks.begin() , tasks.end() , compare);
      int ans = tasks[0][1];
      int residue = tasks[0][1]-tasks[0][0];
      for(int i = 1; i < n; i++){
        if(residue <  tasks[i][1]){
              ans += tasks[i][1] - residue;
               residue = tasks[i][1]-tasks[i][0];
        }else{
            residue = residue-tasks[i][0];
        }
        
      } 
      return ans;
    }
};