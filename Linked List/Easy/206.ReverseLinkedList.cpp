/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseTheLL(ListNode* prev, ListNode* curr) {
        if(curr == NULL) {; 
            return prev;
        }
        ListNode* forward = curr->next;
        curr->next = prev;
        
        return reverseTheLL(curr, forward);
    }
    ListNode* reverseList(ListNode* head) {
        //Approach:1 iterative method to print the reverse of Linked List
        //TC: O(n), SC: O(1)
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = forward;
        }
        return prev;

        //Approach:2 recursive method to reverse the Linked List
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* reverse = reverseTheLL(prev, curr);
        
        return reverse;
    }
};
