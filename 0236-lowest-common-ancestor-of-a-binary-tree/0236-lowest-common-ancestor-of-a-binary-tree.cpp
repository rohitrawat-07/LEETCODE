class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL){
            return nullptr;
        }

        if(root == p || root == q){
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA != NULL && rightLCA != NULL){
            return root;
        }
        else if(leftLCA == NULL){
            return rightLCA;
        }
        else{
            return leftLCA;
        }
    }
};