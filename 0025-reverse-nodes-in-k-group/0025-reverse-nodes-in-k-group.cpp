class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 1){
        return head;
    }
      ListNode* temp = head;
      int size = 0;
      while(temp != NULL){
        size++;
        temp = temp->next;
      }
      if(k > size){
        return head;
      }
    temp = head;
    ListNode* prev = NULL;
    ListNode* tail = head;
    for(int i = 0; i < k; i++){
        ListNode* curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
     ListNode* prevTail = tail;

    for(int i = k; i+k <= size; i+=k){
      ListNode* temp1 = temp;
       ListNode* thisTail = temp1;
       ListNode* x = NULL;
      for(int i = 0; i < k; i++){
        ListNode* curr = temp1->next;
        temp1->next = x;
        x = temp1;
        temp1 = curr;
      }
      thisTail->next = prevTail->next;
      prevTail->next = x;
      prevTail = thisTail;
      temp = temp1;
    }
     prevTail->next = temp;
    return prev;
    }
};

