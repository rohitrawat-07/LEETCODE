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
    void func(TreeNode* root , int mxx , int& count){
      if(root == NULL){
        return;
      } 
      mxx = max(root->val , mxx);
      if(root->val >= mxx){
        count++;
      }
      func(root->left , mxx , count);
      func(root->right , mxx , count);

    }
    int goodNodes(TreeNode* root) {
        int mxx = INT_MIN;
        int count = 0;
        func(root , mxx , count);
        return count;
    }
};




 