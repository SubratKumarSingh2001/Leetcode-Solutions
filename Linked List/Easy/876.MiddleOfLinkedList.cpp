class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //Brute force, TC: O(n), SC: O(1)
        /*we can do it by finding the length of the linked list then if the length is
        odd then return the 3rd node because its middle node and if the length is even 
        then there are two middle nodes send the second middle node 
        */
        //if single node
        if(head->next == NULL) return head;
        
        int cnt=0;
        ListNode* temp = head;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int i = 1;
        int mid = cnt/2;
        while(i < mid+1) {
            temp = temp->next;
            i++;
        }
        return temp;

        //Optimal Solution using The Tortoise and Hare Algorithm, also slow-fast pointers
        //TC: O(n), SC: O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow && fast) {
            /*slow pointer is able to move one node ahead if fast pointer is able to move 
            two nodes ahead
            */
            if(fast != NULL && fast->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
            }
            else {
                fast = fast->next;
            }
        }
        return slow;
    }
};
