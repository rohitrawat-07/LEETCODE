class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int count = 0;
        string ans = "";
        for(int i = 0; i < n; i++){

           if(s[i] == '('){
              count++;
           }
           if(s[i] == ')'){
            count--;
           }


            if(count > 1 && s[i] == '('){
                ans += s[i];
            }
            if(count >= 1 && s[i] == ')'){
                ans+= s[i];
            }
        }
        return ans;
    }
};