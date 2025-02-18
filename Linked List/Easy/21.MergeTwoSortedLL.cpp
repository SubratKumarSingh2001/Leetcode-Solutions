class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //TC: O(n) as where n is number of elements in LL;
        //SC: O(1) created an constant space i.e ans, we had chnage the pointer instead of create new linked list.
        ListNode* ans = new ListNode(-1);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp3 = ans;

        while(temp1 && temp2 ) {
            if(temp1->val <= temp2->val) {
                temp3->next = temp1;
                temp1 = temp1->next;
                temp3 = temp3->next;
            }
            else if(temp1->val > temp2->val) {
                temp3->next = temp2;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
        }
        //when either of linked list becomes empty
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
