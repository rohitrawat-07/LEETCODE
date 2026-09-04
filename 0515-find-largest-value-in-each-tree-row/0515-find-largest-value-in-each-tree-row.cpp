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
   int levels(TreeNode* root){
   if(root == NULL){
   return 0;
   }
   return 1+max(levels(root->left) , levels(root->right));
   }
  

     void func(TreeNode* root , int curr , int level ,int& mxx){
     if(root == NULL){
        return;
     }
     if(curr == level && root->val > mxx){
        mxx = root->val;
        return;
     }
     func(root->left , curr+1, level,  mxx);
     func(root->right , curr+1, level, mxx);
     }


       void help(TreeNode* root, vector<int>& ans){
       int n = levels(root);
       for(int i = 1; i <=n; i++){
        int mxx = INT_MIN;
       func(root , 1 , i, mxx);
       ans.push_back(mxx);
    }
       }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        help(root , ans);
        return ans;
    }
};










