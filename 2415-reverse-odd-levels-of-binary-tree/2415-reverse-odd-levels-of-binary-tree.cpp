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
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> nodes;
            int n = q.size();
           for(int i = 0; i < n; i++){
             TreeNode* curr = q.front();
              q.pop();
              nodes.push_back(curr);
              if(curr->left != NULL){
                q.push(curr->left);
              }
              if(curr->right != NULL){
                q.push(curr->right);
              }
            }
             if(level % 2 != 0){
                int st = 0;
                int end = nodes.size()-1;
                while(st < end){
                    swap(nodes[st]->val , nodes[end]->val);
                    st++; 
                    end--;
                }
             }
            level++;
        }
        return root;
    }
};