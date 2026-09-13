
class Solution {
public:
    TreeNode* inorderSuccesor(TreeNode* root){ // get the inorder successor;;;;
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }
    TreeNode* del(TreeNode* root , int key){
        if(root == NULL){
            return NULL;
        }
        if(root->val < key){
          root->right =  del(root->right , key);
        }
        if(root->val > key){
            root->left = del(root->left , key);
        }
        if(root->val == key){
        // case 1:   when root have 0 child ;

        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
          
        //case 2 : when root have only one child;
        if(root->left == NULL || root->right == NULL){
            if(root->right == NULL){
                return root->left;
            }else{
                return root->right;
            }
        }

       //case 3 : when root have 2 childs;

        TreeNode* is = inorderSuccesor(root->right);
        root->val = is->val;    // get the inorder succesor ad change the value ; after this next step is for deleting the inorder succesor node;
        root->right = del(root->right , is->val); // is->val is the key in this step so we have to pass as argument ;
        
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
     return del(root , key);
    
    }
};