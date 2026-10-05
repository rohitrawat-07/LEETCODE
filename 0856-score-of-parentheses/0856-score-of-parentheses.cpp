class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<string> st;
      for(int i = 0; i < n; i++){
         if(s[i] == '('){
            st.push(("("));
         }else if(s[i] == ')'){
            if(st.top() == "("){
                st.pop();
                st.push(to_string(1));
                
            }else if(st.top() != "("){
                 int x = 0;
                 while(st.top() != "("){
                    x += stoi(st.top());
                    st.pop();
                 }
                 st.pop();
                 x = x * 2;
                 string ch = to_string(x);
                 st.push(ch);
            }

         }
      }
      int ans = 0;
      while(!st.empty()){
        ans += stoi(st.top());
        st.pop();
      }
      return ans;
    }
};