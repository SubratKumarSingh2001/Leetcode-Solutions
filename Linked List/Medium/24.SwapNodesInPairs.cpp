class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //Iterative Solution 
        //TC: O(n/2) overall O(n), SC: O(1)
        //Same as the "LC:25 Reverse the Nodes in k-Groups (Hard Problem)"
        //edge case when we have no nodes and single node handle explicitly
        if(head == NULL || head->next == NULL) return head;

        //for more than one nodes in a linked list
        ListNode* t1 = head;
        ListNode* prev = NULL;
        while(t1) {
            ListNode* t2 = t1->next;
            ListNode* t3 = NULL;
            if(t2) {
                t3 = t2->next;
            }
            else {
                prev->next = t1;
                break;
            }

            //now swaping the nodes in pairs not by value by changing the nodes links
            t2->next = t1;
            t1->next = NULL;

            if(t1 == head) {
                head = t2;
            }
            else {
                prev->next = t2;
            }
            prev = t1;
            t1 = t3;
        }
        return head;

        //Recursive Solution
        //TC: O(n), SC: O(n)[Due to the recursive call stack]
        if(head == NULL || head->next == NULL) return head;

        ListNode* t1 = head;
        ListNode* t2 = t1->next;
        ListNode* t3 = NULL;
        if(t2) {
            t3 = t2->next;
        }

        //now swapping the nodes in pairs
        t2->next = t1;
        t1->next = NULL;

        //now recursive calling
        t1->next = swapPairs(t3);

        //return our new head 
        return t2;
    }
};
