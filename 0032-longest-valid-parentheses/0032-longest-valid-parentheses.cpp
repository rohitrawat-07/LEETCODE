class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int num = 0;
        int mxx = INT_MIN;
        for(int i = 0; i < n; i++){
            if(!st.empty() && s[i] == ')'){
                if(s[st.top()] == '('){
                     st.pop();
                }else{
                    st.push(i);
                }
            }
            else{
                st.push(i);
            }
        }
        vector<int> ans;
        ans.push_back(n-1);
        if(st.empty()){
            return s.size();
        }else{
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
        ans.push_back(0);
        for(int i = 0; i < ans.size()-1; i++){
         mxx = max(abs(ans[i+1]-ans[i] ), mxx);
        }
         if(mxx % 2 != 0){
            return mxx-1;
         }
         return mxx;
       
    }
};