/**
 * ky re lodu ........
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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(height(root->left) , height(root->right));

    }
     void func(TreeNode* root , int& mxx){
      if(root == NULL){
        return;
      }
       mxx = max(height(root->left)+height(root->right) , mxx);
       func(root->right , mxx);
       func(root->left , mxx);
     }
    int diameterOfBinaryTree(TreeNode* root) {
            if(root == NULL){
                return 0;
            }          
       int mxx = INT_MIN;
        func(root , mxx);
        return mxx;
    
    }
};