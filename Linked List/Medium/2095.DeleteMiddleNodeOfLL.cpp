class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        //either the linked list is null or a single node return null
        if(head == NULL || head->next == NULL) return NULL;

        //Approach:1 Brute Force
         //TC: O(n), SC: O(1)
        int cnt=0;
        ListNode* temp = head;
        while(temp) {
            cnt++;
            temp = temp->next;;
        }
        temp = head;
        int i=1;
        while(i < cnt/2) {
            temp = temp->next;
            i++;
        }
        ListNode* forward = temp->next;
        temp->next = forward->next;

        return head;

        //Approach:2 Using Tortoise-Hare Algo, (slow-fast pointer)
        //TC: O(n), SC: O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast && fast->next != NULL) {
            if(prev != slow) prev = prev->next;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = slow->next;

        return head;
    }
};
