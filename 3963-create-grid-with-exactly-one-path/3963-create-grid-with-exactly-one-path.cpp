class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<string> ans;
       string t = "";
       for(int i = 0; i < n; i++){
         t += '.';
       }
       ans.push_back(t);
       
        for(int i = 1; i < m; i++){
            string temp = "";
            for(int j = 0; j < n ; j++){
              if(j == n-1){
                temp += '.';
              }else{
                temp += '#';
              }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};