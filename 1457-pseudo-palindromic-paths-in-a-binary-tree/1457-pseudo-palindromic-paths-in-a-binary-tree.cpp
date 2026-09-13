class Solution {
public:
    void func(TreeNode* root, unordered_map<int, int>& m, int& ans, int count) {
        if (root == NULL) {
            return;
        }

        m[root->val]++;
        if (root->left == NULL && root->right == NULL) {
            for (auto& el : m) {
                if ((el.second % 2) != 0) {
                    count++;
                }
            }
            if (count == 1 || count == 0) {
                ans++;
            }

            m[root->val]--;
            return;
        }

        func(root->left, m, ans, count);
        func(root->right, m, ans, count);
        m[root->val]--;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> m;
        int ans = 0;
        func(root, m, ans, 0);
        return ans;
    }
};