class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {\
        //TC: O(n) where n is number of nodes in Linked List
        if(head->next == NULL) {
            delete head; 
            return NULL;
        }

        ListNode* temp = head;
        int count=0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        if(count == n) {
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }

        int i=1;
        temp = head;
        while(i<count-n) {
            temp = temp->next;
            i++;
        }
        ListNode* target = temp->next;
        ListNode* forward = target->next;
        temp->next = forward;
        target->next = NULL;
        delete target;

        return head;

        //Optimal Way: Two pointers i.e Slow and Fast Pointers (Tortoise and Hare)
        //will do it later..........
    }
};
