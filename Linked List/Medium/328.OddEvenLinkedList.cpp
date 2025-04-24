class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //Approach:1 Brute Force
        /*We can store the elements in array like all odd elements are placed first then
        even elements and then convert that array into a linked list
        */
        //TC: O(n), SC: O(n)

        //Approach:2 Two-pointers approach
        //TC: O(n), SC: O(1)
        //if no node in the linked list and single node
        if(head == NULL || head->next == NULL) return head;

        //more than single node
        ListNode* temp = head->next;
        ListNode* slow = head;
        ListNode* fast = temp;
        while(slow && slow->next != NULL) {
            ListNode* odd = fast->next;
            slow->next = odd;
            if(odd) {
                ListNode* even = odd->next;
                fast->next = even;
                slow = odd;
                fast = even;
            }
        }
        slow->next = temp;

        return head;
    }
};
