class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && s[i] == ')' && st.top() == ')') {
                char ch = st.top();
                st.pop();
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    st.push('#');         
                    continue;
                } else {
                    st.push(ch);
                    st.push(s[i]);
                    continue;
                }
            }
            st.push(s[i]);              
        }
        string t;
        while (!st.empty()) {
            t.push_back(st.top());
            st.pop();
        }
        reverse(t.begin(), t.end());

        int open = 0, count = 0, m = t.size();
        for (int i = 0; i < m; i++) {
            if (t[i] == '(') {
                open++;
            } else if (t[i] == ')') {
                if (i + 1 < m && t[i + 1] == ')') i++;   
                else count++;                            

                if (open > 0) open--;
                else count++;                          
            }
        }
        return count + 2 * open;          
    }
};