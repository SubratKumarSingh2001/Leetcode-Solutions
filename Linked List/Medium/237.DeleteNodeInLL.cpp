class Solution {
public:
    void deleteNode(ListNode* node) {
        /*we can do it by swapping the value of this node (the node we want to delete)
        with the next node val, and to avoid the duplicacy we will delete the the next node
        of the node you want to delete
        */
        /*Point to Remember
        Here we can see that we are not deleting the node which we want to just swap-
        -ping the next value data and deleting the next node of the node we want to 
        delete to avoid duplicacy
        */

        //TC: O(1), SC: O(1)
        ListNode* curr = node;
        ListNode* forward = curr->next;
        ListNode* forwardNext = forward->next;

        //swap the values means (data)
        curr->val = forward->val;
        curr->next = forwardNext;

        delete(forward);
    }
};
