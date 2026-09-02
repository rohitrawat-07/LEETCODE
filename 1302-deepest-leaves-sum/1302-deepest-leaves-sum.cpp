class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+max(height(root->left) , height(root->right));
    }
   void leavesSum(TreeNode* root, int& sum, int count , int x){
    if(root == NULL){
        return;
    }
    if(count == x-1){
        sum+=root->val;
    }

     leavesSum(root->left , sum , count+1, x);
     leavesSum(root->right , sum , count+1, x);
   }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int x = height(root);
        leavesSum(root , sum , 0 , x);
        return sum;
    }
};