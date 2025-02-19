class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //TC: O(n), SC: O(1) (as no extra space taken)
        if(head == NULL) return head;
        //if head is target value
        while(head != NULL && head->val == val) {
            //it is not necessary to delete the node we can just move head
            head = head->next;
        }
        
        //other than head
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL) {
            if(temp->next->val != val) {
                temp = temp->next;
            }
            else {
                ListNode* curr = temp->next;
                if(curr != NULL) {
                    ListNode* forward = curr->next;
                    temp->next = forward;
                    curr->next = NULL;
                    delete curr;
                }
            }
        }
        return head;
    }
};
