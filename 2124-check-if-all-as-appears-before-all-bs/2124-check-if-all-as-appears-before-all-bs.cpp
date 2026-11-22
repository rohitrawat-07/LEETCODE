class Solution {
public:
    bool checkString(string s) {
      int n = s.size();
      int aidx = -1;
      int bidx = -1;
      for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            aidx = i;
        }
      }
      for(int i = n-1; i >= 0; i--){
        if(s[i] == 'b'){
            bidx = i;
        }
      }
      if(aidx == -1 || bidx == -1){
          return true;
      }
      if(aidx < bidx){
        return true;
      }
      return false;
    }
};