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
    void func1(TreeNode* root , vector<int>& ans , int& idx){
        if(root == NULL || idx >= ans.size()){
            return;
        }
         func1(root->left , ans , idx);
         root->val = ans[idx];
         idx++;
         func1(root->right , ans , idx);
    }
    void func(TreeNode* root , vector<int>& ans){
        if(root == NULL){
            return;
        }
        func(root->left , ans);
        ans.push_back(root->val);
        func(root->right , ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        int idx = 0;
        func(root , ans);
        sort(ans.begin() , ans.end());  
        func1(root , ans , idx);
    }
};




