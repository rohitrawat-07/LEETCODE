class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         set<int> row;
         set<int> column;
         int n = matrix.size();
         int m = matrix[0].size();
         for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               if(matrix[i][j] == 0){
                row.insert(i);
                column.insert(j);
               }
            }
         }
         for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row.count(i) || column.count(j)){
                    matrix[i][j] = 0;
                }
            }
         }
    }
};