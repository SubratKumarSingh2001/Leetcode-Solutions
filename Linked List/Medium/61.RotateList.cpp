class Solution {
public:
    int length(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while(temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        //ONE WAY TO DO THIS
        //TC: O(n)+O(n)+O(n) = O(n), SC: O(1)
        // if no node present and single node
        if (head == NULL || head->next == NULL || k==0) {
            return head;
        }

        int len = length(head);
        if(k == len) return head;
        k = k % len;
        ListNode* slow = head;
        for(int i=0; i<len-k-1; i++) {
            slow = slow->next;
        }
        ListNode* fast = slow->next;
        ListNode* temp = fast;
        if(slow->next != NULL) {
            slow->next = NULL;
        }
        else {
            return head;
        }

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
        head = fast;

        return head;

        //ANOTHER WAY TO DO THIS QUESTION 
        //TC: O(n)+O(n)+O(n) = O(n), SC: O(1)
        if(head == NULL || head->next == NULL || k==0) {
            return head;
        }
        ListNode* temp = head;
        int len=1;
        while(temp->next != NULL) {
            len++;
            temp = temp->next;
        }
        
        k = k % len;
        int end = len-k-1;
        ListNode* ptr = head;

        while(end--) {
            ptr = ptr->next;
        }

        ListNode* ptrNext = ptr->next;
        if(ptrNext) {
            ptr->next = NULL;
            temp->next = head;
            head = ptrNext;
        }
        return head;
    }
};
