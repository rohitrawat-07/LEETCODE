class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            st.push(s[i]);
            if (st.top() == ')') {
                string a = "";
                while (st.top() != '(') {
                    a += st.top();
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                a += st.top();
                if (!st.empty()) {
                    st.pop();
                }
                if (a.size() > 2) {
                    for (int j = 1; j < a.size() - 1; j++) {
                        st.push(a[j]);
                    }
                }
                a = "";
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
