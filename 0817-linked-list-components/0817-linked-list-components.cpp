/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> s;
        int count = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }
        ListNode* temp = head;
      while(temp != NULL){
        if(s.find(temp->val) != s.end()){
            count++;
        }else{
            if(count > 0){
                ans++;
                count = 0;
            }
        }
        temp = temp->next;
      }
       if(count > 0){
        ans++;
       }
      return ans;
    }
};