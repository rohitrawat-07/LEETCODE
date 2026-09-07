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
     void func(TreeNode* root , int sum , int& level , int& ans , int& maxSum){
        if(root == NULL){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
             level++;
            if(sum > maxSum){
                maxSum = sum;
                ans = level;
            }
        }
     }
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        int level = 0;
        int maxSum = INT_MIN;
        func(root , 0 , level , ans , maxSum);
        return ans;
    }
};