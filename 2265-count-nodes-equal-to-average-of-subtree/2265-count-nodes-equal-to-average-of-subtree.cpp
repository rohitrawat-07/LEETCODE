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
    int addAllNodes(TreeNode* root){
        if(root == NULL){
            return 0;
        }
       
       int left = addAllNodes(root->left);
       int right = addAllNodes(root->right);
      return left+right+root->val;
    }
     int countNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
      return 1 + countNodes(root->left) + countNodes(root->right);
  } 
    void countAvg(TreeNode* root , int& count){
        if(root == NULL){
            return;
        }
        int x = addAllNodes(root);
        int y = countNodes(root);
        if(root->val == x/y){
            count++;
        }
        countAvg(root->left , count);
        countAvg(root->right , count);
        
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        countAvg(root , count);
        return count;
    }
};