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
    TreeNode* func(vector<int>& preorder, vector<int>& inorder , int st , int end , int& idx){
        if(st > end){
            return NULL;
        }
        int rootVal = preorder[idx];
        int i = st;
        while(i <= end){
            if(inorder[i] == rootVal){
                break;
            }
            i++;
        }
        idx++;
       TreeNode* root = new TreeNode(rootVal);
        root->left = func(preorder , inorder , st , i-1,idx);
        root->right = func(preorder , inorder , i+1 , end,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return func(preorder , inorder , 0 , n-1 , idx);
    }
};