class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //TC: O(n) where n is the no.of nodes, SC: O(1)
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL) {
            if(temp->val != temp->next->val) {
                temp = temp->next;
            }
            else {
                ListNode* forward = temp->next;
                temp->next = forward->next;
            }
        }
        return head;
    }
};
