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
    void func(TreeNode* root , int& minn , long long& secondminn){
        if(root == NULL){
            return;
        }
        if(root->val < minn){
            secondminn = minn;
            minn = root->val;
        }else if(root->val > minn && root->val < secondminn){
              secondminn = root->val;
        }
        func(root->left , minn , secondminn);
        func(root->right , minn , secondminn);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int minn = INT_MAX;
       long long secondminn = LLONG_MAX;
        func(root , root->val , secondminn);
          if(secondminn == LLONG_MAX ) {
            return -1;
        }
        return (int)secondminn;

    }
};