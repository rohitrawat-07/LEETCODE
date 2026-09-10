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

    long long int func(TreeNode* root, long long int& total,
                       long long int& mxx) {
         if(root == NULL){
            return 0;
        }
        long long int left = func(root->left, total, mxx);
        long long int right = func(root->right, total, mxx);
        long long int value = root->val + left + right;
        mxx = max(mxx, value * (total - value));
        return value;
    }
    long long int summ(TreeNode* root, long long int& sum){
        if(root == NULL){

            return 0;
        }

        sum += root->val;

        summ(root->left, sum);
        summ(root->right, sum);

        return sum;
    }

    int maxProduct(TreeNode* root) {

        long long int mxx = 0;
        long long int sum = 0;

        long long int s = summ(root, sum);

        func(root, s, mxx);

       return mxx % 1000000007;

    }
};




