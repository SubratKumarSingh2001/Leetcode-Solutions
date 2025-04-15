class Solution {
public:
    int getDecimalValue(ListNode* head) {
        //TC: O(n), where n is the length of Linked List, SC: O(1)
        ListNode* temp = head;
        int count = 0;
        while(temp) {
            count++;
            temp = temp->next;
        }
        
        temp = head;
        int sum = 0;
        for(int i=count-1; i>=0; i--) {
            sum = sum + pow(2,i)* temp->val;
            temp = temp->next;
        }
        return sum;
    }
};
