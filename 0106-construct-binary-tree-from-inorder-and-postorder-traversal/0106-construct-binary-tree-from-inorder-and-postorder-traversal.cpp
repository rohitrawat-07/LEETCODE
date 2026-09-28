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
    TreeNode* func(vector<int>& inorder, vector<int>& postorder , int st , int end , int& idx){
        if(st > end){
            return nullptr;
        }
        int rootVal = postorder[idx];
        int i = 0; 
        while(i <= end){
         if(inorder[i] == rootVal){
            break;
         }
         i++;
        }
        idx--;
         TreeNode* root = new TreeNode(rootVal);
        root->right = func(inorder , postorder , i+1 , end , idx);
        root->left = func(inorder , postorder , st , i-1 , idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        return func(inorder , postorder , 0 , n-1 , idx);
    }
};