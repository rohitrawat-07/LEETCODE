class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
      sort(s1.begin() , s1.end());
      int n = s1.size();
      sort(s2.begin() , s2.end());
      bool ans1 = true;
      bool ans2 = true;;
      for(int i = 0; i < n; i++){
        if(s1[i] < s2[i]){
            ans1 = false;
        }
      }
      for(int i = 0; i < n; i++){
        if(s2[i] < s1[i]){
            ans2 = false;
        }
      }
      if(ans1 || ans2){
        return true;
      }
      return false;
    }
};