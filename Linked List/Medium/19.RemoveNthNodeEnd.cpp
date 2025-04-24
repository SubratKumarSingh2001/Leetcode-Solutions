class Solution {
public:
    int cntNodes(ListNode* head) {
        int cnt=0;
        ListNode* temp = head;
        while(temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //if the node delete is the first node 
        //Brute Force
        //TC: O(len)+O(len-n) for worse n=1(delete last node), Therfore TC: O(2*len)
        //SC: O(1)
        int cnt = cntNodes(head); //cnt is number of nodes in linked list
        if(cnt == n) {
            head = head->next;
            return head;
        }

        //for value of n>1, code below will be the logic
        int i=1;
        ListNode* temp = head;
        while(i < cnt-n) {
            temp = temp->next;
            i++;
        }
        ListNode* forward = temp->next;
        temp->next = forward->next;

        return head;

        //Optimal Approach
        //TC: O(n), n is lenght of the nodes, SC: O(1)
        /*We have use slow and fast pointers as we need to delete the nth node from the 
        last which means we need a pointer that points the previous node of the node that
        we want to delete, if we want to delete the nth node from last wich means we need
        to move ahead the len-n nodes from beginning for which we dont need the no. of
        nodes in Linked List we will traverse the pointer until n times which will autom-
        -atically help us to move ahead len-n nodes, so to reach on prev node of delete
        node move two pointers i.e slow anf fast one node ahead until fast->next != NULL
        . Its basically a mathematical obseravtion
        */
        ListNode* fast = head;
        for(int i=0; i<n; i++) {
            fast = fast->next;
        }
        if(fast == NULL) { //when n=len of the linked list
            head = head->next;
            return head;
        }
        ListNode* slow = head;
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        //now we have to delete the node
        ListNode* temp = slow->next;
        slow->next = temp->next;
        temp->next = NULL;
        delete(temp);

        return head;
    }
};
