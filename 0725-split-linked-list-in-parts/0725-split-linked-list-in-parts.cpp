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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        vector<ListNode*> ans;
        int size = 0;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        ListNode* x = head;
        if (size <= k) {
            int i = 0;
            while (i < k) {
                ListNode* curr = x;
                if (x != NULL) {
                    x = x->next;
                    curr->next = NULL;
                }
                ans.push_back(curr);
                i++;
            }
        } else {
            ListNode* a = head;

            while (a != NULL && k > 0) {
                ListNode* value = a;
                int finalval = (size + k - 1) / k;
                ListNode* comp = a;

                for (int i = 1; i < finalval; i++) {
                    comp = comp->next;
                }
                a = comp->next;
                comp->next = NULL;
                ans.push_back(value);
                size = size - finalval;
                k--;

            }
        }
        return ans;
    }
};





