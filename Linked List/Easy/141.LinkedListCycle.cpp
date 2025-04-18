class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Tortoise-Hare Algorithm, slow-fast pointers
        //for worse case the loop will run till end to check whether fast null or not
        //TC: O(n), SC: O(1);S
        // if single node
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return false;

        // other than single node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            // if slow and fast point to same node
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
