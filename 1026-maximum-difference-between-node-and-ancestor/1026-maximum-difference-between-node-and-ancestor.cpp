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
   void func(TreeNode* root ,int mxx , int mnn , int& ans ){
    if(root == NULL){
        return;
    }
     mxx = max(root->val , mxx);
     mnn = min(root->val , mnn);
     if(root->left == NULL && root->right == NULL){
         ans = max(abs(mxx-mnn) , ans);
         return;
     }
    
     
    func(root->left , mxx , mnn , ans);
    func(root->right, mxx , mnn , ans);
    return;
   }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        func(root , INT_MIN , INT_MAX , ans);
        return ans;
    }
};