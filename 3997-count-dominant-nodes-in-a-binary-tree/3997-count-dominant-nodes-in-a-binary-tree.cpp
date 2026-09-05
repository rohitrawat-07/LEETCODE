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
   bool isSmall(TreeNode* root, int x){
    if(root == NULL){
        return true;
    }
     if(x < root->val){
        return false;
     }
     bool left  = isSmall(root->left , x);
     bool right =  isSmall(root->right, x);
     if(left && right){
        return true;
     }
     return false;
   }
    void func(TreeNode* root , int& count){
        if(root == NULL){
            return;
        }
         if(isSmall(root , root->val)){
            count++;
         }
        func(root->left , count);
        func(root->right, count);
    }
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        func(root , count);
        return count;
    }
};