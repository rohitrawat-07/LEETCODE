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
    int func(TreeNode* root , map<int , int>& ans){
        if(root == NULL){
            return 0;
        }
        int leftsum = func(root->left , ans);
        int rightsum = func(root->right , ans);
        int sum = root->val + leftsum + rightsum;
        ans[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int , int > ans;
        func(root , ans);
        int mxx = 0;
    for(auto& el : ans){
        if(el.second > mxx){
            mxx = el.second;
        }
    }
      vector<int> v;
      for(auto& it: ans){
       if(it.second == mxx){
        v.push_back(it.first);
       }
      }
      return v;
    }
};