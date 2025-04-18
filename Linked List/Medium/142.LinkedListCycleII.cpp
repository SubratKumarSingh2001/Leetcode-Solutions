class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //if no linked list is present 
        //TC: O(n), SC: O(1)
        if(head == NULL) return NULL;
        //if single node 
        if(head->next == NULL) return NULL;

        //other than single node
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            //if slow and fast pointer points to same node means the cycle present
            if(slow == fast) {
                slow = head;
                break;
            }
        }
        while(slow != fast && fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        //If there is loop for sure fast will not be null, Therefore return fase
        if(fast != NULL) return fast;

        return NULL;
    }
};
