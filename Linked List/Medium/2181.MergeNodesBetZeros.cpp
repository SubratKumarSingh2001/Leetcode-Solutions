class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        //Brute Force
        //TC: O(n), n is length of the Linked List
        /*SC: O(m-1) = O(m) where m is the number of zero nodes in the Linked List or 
        the nodes segmented by 0 nodes. m<n and m != n (because the Linked List must have
        minimum of three node and atleast 1 node with non-zero value
        */
        ListNode* temp = head->next; //as there are minimum three nodes, head cant be NULL
        ListNode* dummyNode = new ListNode(-1);
        ListNode* ptr = dummyNode;
        int sum = 0;
        while(temp) {
            if(temp->val != 0) {
                sum += temp->val;
            }
            else {
                ListNode* newNode = new ListNode(sum);
                ptr->next = newNode;
                ptr = ptr->next;
                sum = 0;
            }
            temp = temp->next;
        }
        return dummyNode->next;

        //Better Soluion
        //TC: O(n+n = 2n) = O(n), SC: O(1) (No extra space taken)
        ListNode* t1 = head;
        while(t1->next != NULL) {
            ListNode* t2 = t1->next;
            ListNode* t3 = t2->next;
            if(t3->val != 0) {
                t2->val = t2->val + t3->val;
                t2->next = t3->next;
            }
            else {
                t1 = t3;
            }
        }
        head = head->next; //to move ahead with initial 0 node
        t1 = head;
        while(t1) {
            ListNode* t2 = t1->next;
            t1->next = t2->next;
            t1 = t1->next;
        }
        return head;

        //Optimal Solution
        //TC: O(n), SC: O(1)
        ListNode* slow = head;
        ListNode* fast = slow->next;
        ListNode* last = NULL;
        int sum=0;
        while(fast) {
            if(fast->val != 0) {
                sum += fast->val;
            }
            else {
                slow->val = sum;
                last = slow;
                slow = slow->next;
                sum=0;
            }
            fast = fast->next;
        }
        last->next = NULL; // to make linked list separate

        return head;
    }
};
