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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       vector<int> ans;
       ListNode* prev = head;
       ListNode* curr = head->next;;
       ListNode* nxt = head->next->next;
       if(head->next == NULL) return {-1,-1};
       if(head->next->next == NULL) return {-1 , -1};
       int x = 1;
       while(nxt != NULL){
        if((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)){
            ans.push_back(x);
            
           
        }
            x++;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
       }
        int a = INT_MAX;
        int b = -1;
       if(ans.size() == 0 || ans.size() == 1){
          return {-1 , -1};
       }
       for(int i = 1; i < ans.size(); i++){
           a = min(ans[i]-ans[i-1] , a);
       }
       return {a , ans[ans.size()-1]-ans[0]};
    }
};