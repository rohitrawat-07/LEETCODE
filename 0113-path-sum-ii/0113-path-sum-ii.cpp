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
    void func(TreeNode* root , vector<int> ans, vector<vector<int>> & anss , int sum , int targetSum){
        if(root == nullptr){
            return;
        }
        sum+=root->val;
        ans.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                anss.push_back(ans);
                return;
            }
        }
        func(root->left , ans , anss,sum,targetSum);
        func(root->right , ans , anss,sum,targetSum);
       

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> ans;
        vector<vector<int>> anss;
        func(root , ans , anss, sum , targetSum);
        return anss;
    }
};