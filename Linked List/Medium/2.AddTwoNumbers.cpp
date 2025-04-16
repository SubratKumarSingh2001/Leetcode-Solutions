class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //TC: O(max(n,m)) where n and m is length of each linked list, SC: O(n)
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* ans = new ListNode(-1);
        ListNode* t3 = ans;
        int carry = 0;
        while(t1 && t2) {
            int sum = t1->val + t2->val + carry;
            int rem = sum % 10;
            ListNode* newNode = new ListNode(rem);
            t3->next = newNode;
            t1 = t1->next;
            t2 = t2->next;
            t3 = t3->next;
            carry = sum/10;
        }
        //if either of linked list finish
        while(t1) {
            int sum = t1->val + carry;
            int rem = sum % 10;
            ListNode* newNode = new ListNode(rem);
            t3->next = newNode;
            t1 = t1->next;
            t3 = t3->next;
            carry = sum/10;
        }
        while(t2) {
            int sum = t2->val + carry;
            int rem = sum % 10;
            ListNode* newNode = new ListNode(rem);
            t3->next = newNode;
            t2 = t2->next;
            t3 = t3->next;
            carry = sum/10;
        }
        //if there is still any carry
        if(carry) {
            ListNode* newNode = new ListNode(carry);
            t3->next = newNode;
        }

        return ans->next;
    }
};
