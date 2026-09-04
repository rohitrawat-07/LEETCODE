/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int numoflevels(TreeNode* root){
      if(root == nullptr){
        return 0;
     }
     int lf = numoflevels(root->left);
      int r = numoflevels(root->right);
      if(lf == -1 || r == -1){
        return -1;
      }
      if(abs(r-lf) > 1){
        return -1;
      }
      return 1+max(lf,r);
     }
     bool isBalanced(TreeNode* root) {
      if(numoflevels(root) == -1){
        return false;
      }
      return true;
    }
};




 