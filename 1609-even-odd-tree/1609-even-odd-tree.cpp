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
    bool bfs(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
    
         int level = 0;
        while (!q.empty()) {
           vector<int> ans;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                ans.push_back(curr->val);
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            if (ans.size() == 1) {
                if (level % 2 == 0 && ans[0] % 2 == 0) {
                    return false;
                }
                if (level % 2 != 0 && ans[0] % 2 != 0) {
                    return false;
                }

            } else {
                for (int i = 0; i < ans.size() - 1; i++) {
                    if (level % 2 == 0) {
                        if (ans[i] % 2 == 0 || ans[i] >= ans[i + 1] ||
                            ans[ans.size() - 1] % 2 == 0) {
                            return false;
                        }
                    }
                    if (level % 2 != 0) {
                        if (ans[i] % 2 != 0 || ans[i] <= ans[i + 1] ||
                            ans[ans.size()-1] % 2 != 0) {
                            return false;
                        }
                    }
                }
            }
            level++;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) { 
        return bfs(root);
         }
};