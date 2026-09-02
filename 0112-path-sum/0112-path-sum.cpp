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
    int summ(TreeNode* root , int targetSum,int sum){
      if(root == NULL){
        return false;
      }
      sum += root->val;
      if(root->left == NULL && root->right == NULL){
      return sum == targetSum;
      }
     bool first = summ(root->left ,targetSum , sum);
     bool second= summ(root->right ,targetSum , sum);
       return first || second;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
      if(root == NULL) return false;
      return summ(root , targetSum , 0);
    }
};