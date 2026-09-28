class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int mxx = 0;
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            st.push(s[i]);
            if(st.top() == '('){
                count++;
            }else if(st.top() == ')'){
                count--;
            }
            mxx = max(count , mxx);
        }

         return mxx; 
    }
};