class Solution {
public:
    void generate(int n, int m, string p, vector<string>& ans) {
        if (n == 0 && m == 0) {
            ans.push_back(p);
             return;
        }
        if (n > 0) {
            generate(n - 1, m, p + '(', ans);
        }
        if (m > n) {
            generate(n, m - 1, p + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        string p = "";
        vector<string> ans;
        generate(n, n, p, ans);
        return ans;
    }
};