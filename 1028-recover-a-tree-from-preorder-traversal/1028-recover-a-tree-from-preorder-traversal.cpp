/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* BuildTree(TreeNode* root, vector<int>& nums, vector<int>& dashes,
                        int& numsI, int& idx, int level) {
        if (idx == dashes.size()) {
            return root;
        }
        if (dashes[idx] < level) {
            return root;
        }

        if (dashes[idx] > level) {
            root->left = new TreeNode(nums[numsI++]);
            idx++;
            BuildTree(root->left, nums, dashes, numsI, idx, level + 1);
        }
        if (idx == dashes.size()) {
            return root;
        }
        if (dashes[idx] > level) {
            root->right = new TreeNode(nums[numsI++]);
            idx++;
            BuildTree(root->right, nums, dashes, numsI, idx, level + 1);
        }

        return root;
    }
    TreeNode* recoverFromPreorder(string t) {
        int n = t.size();
        string temp = "";
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            if (t[i] >= '0' && t[i] <= '9') {
                temp += t[i];
            } else if (t[i] == '-' && t[i - 1] >= '0' && t[i - 1] <= '9') {
                int x = stoi(temp);
                temp = "";
                vec.push_back(x);
            }
        }
        int x = stoi(temp);
        vec.push_back(x);
        // dashes ;;;;;
        vector<int> dashes;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (t[i] == '-') {
                count++;
            } else if (i == 0 || t[i - 1] == '-') {
                dashes.push_back(count);
                count = 0;
            }
        }

        // function calls
        int numsI = 1;
        int idx = 1;
        TreeNode* root = new TreeNode(vec[0]);
        return BuildTree(root, vec, dashes, numsI, idx, 0);
    }
};