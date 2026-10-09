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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* dummy = new ListNode(-1);
     ListNode* temp = dummy;
     ListNode* first = l1;
     ListNode* second = l2;
     int carry = 0;
     while(first != NULL && second != NULL){
        int x = first->val +second->val+carry;
        if(x < 10){
            carry = 0;
            temp->next = new ListNode(x);
            temp = temp->next;
        }else if(x >= 10){
            temp->next = new ListNode(x%10);
            temp = temp->next;
            carry = x/10;
        }
         first = first->next;
     second = second->next;
     }
     while(first != NULL){
        int y = first->val+carry;
        if(y < 10){
            carry = 0;
            temp->next = new ListNode(y);
            temp = temp->next;
        }else if(y >= 10){
            temp->next = new ListNode(y%10);
            temp = temp->next;
            carry = y/10;
        }
         first = first->next;
     }
     while(second != NULL){
        int y = second->val+carry;
        if(y < 10){
            carry = 0;
            temp->next = new ListNode(y);
            temp = temp->next;
        }else if(y >= 10){
            temp->next = new ListNode(y%10);
            temp = temp->next;
            carry = y/10;
        }
         second = second->next;
     }
     if(carry > 0){
        temp->next = new ListNode(carry);
     }
     return dummy->next;
    }
};