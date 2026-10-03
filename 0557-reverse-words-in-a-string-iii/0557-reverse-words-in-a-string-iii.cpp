class Solution {
public:
    string reverseWords(string s) {
     s+=' ';
     int n = s.size();
     string temp = "";
     string ans = "";
     for(int i = 0; i < n; i++){
      if(s[i] == ' '){
        reverse(temp.begin() , temp.end());
        ans+= temp+' ';
        temp = "";
      }else{
        temp += s[i];
      }
     }
     ans.pop_back();
     return ans;
    }
};