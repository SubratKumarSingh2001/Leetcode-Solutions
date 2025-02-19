class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //TC: O(n) where n is no.of nodes in LL
        //SC: O(1)
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL) {
            if(temp->val != temp->next->val) {
                temp = temp->next;
            }
            else {
                ListNode* curr = temp->next;
                ListNode* forward = curr->next;
                temp->next = forward;
                curr->next = NULL;
                delete curr;
            }
        }
        return head;
    }
};
