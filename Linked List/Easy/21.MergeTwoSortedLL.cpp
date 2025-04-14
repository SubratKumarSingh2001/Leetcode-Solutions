class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //TC: O(n+m) n and m are length of either linked list , SC: O(1) no extra space
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* ans = new ListNode(-1);
        ListNode* temp3 = ans;
        while(temp1 && temp2) {
            if(temp1->val <= temp2->val) {
                temp3->next = temp1;
                temp1 = temp1->next;
            }
            else {
                temp3->next = temp2;
                temp2 = temp2->next;
            }
            temp3 = temp3->next;
        }

        while(temp1) {
            temp3->next = temp1;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        while(temp2) {
            temp3->next = temp2;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }

        return ans->next;
    }
};
