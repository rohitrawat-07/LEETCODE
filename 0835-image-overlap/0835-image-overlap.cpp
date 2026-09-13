class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int , int>> a;
        vector<pair<int , int>> b;
         map<pair<int ,int> , int> m;
          for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1){
                 a.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    b.push_back({i , j});
                }
            }
        }
      
        int ans = 0;
        for(auto& el1 : a){
            for(auto& el2 : b){
                int x = el2.first-el1.first;
                int y = el2.second-el1.second;
                m[{x , y}]++;
                ans = max(ans , m[{x,y}]);
            }
        }
        return ans;
    }
};