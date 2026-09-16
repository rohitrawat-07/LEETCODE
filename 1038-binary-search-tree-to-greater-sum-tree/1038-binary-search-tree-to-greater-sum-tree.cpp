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
    void func(TreeNode* root , vector<int>& a , int& idx){
      if( root == NULL || idx == a.size()){
        return;
      }
       func(root->left , a , idx);
       idx++;
       root->val = a[idx];
       func(root->right , a , idx);
      
    }
    void inorder(TreeNode* root , vector<int>& ans){
        if(root == NULL){
            return;
        }
        inorder(root->left , ans);
        ans.push_back(root->val);
        inorder(root->right , ans);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> ans;
        int idx = -1;
        inorder(root , ans);
        for(int i = ans.size()-2; i>=0; i--){
           ans[i] = ans[i]+ans[i+1];
        }
        func(root , ans , idx);
         return root;
    }
};