class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* forward = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        //Approach:1 Brute Force, Convert this linked list into array then check palindrome
        //TC: O(n), SC: O(n)
        //if single node then it is always palindrome 
        if(head->next == NULL) return true;
        ListNode* temp = head;
        vector<int> ans;
        while(temp) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        //now we will aplly 2-pointers approach in array to check palindrome or not
        int i=0, j=ans.size()-1;
        bool flag = true;
        while(i <= j) {
            if(ans[i] == ans[j]) {
                i++;
                j--;
            }
            else {
                flag = false;
                break;
            }
        }
        return flag;

        /*Approach:2 Tortoise-Hare ALgo find middle and then divide the LL two halfes and
        then compare both the linked to find its palindrome or not
        */
        //TC: O(n), SC: O(1)
        //if single node
        if(head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //now we got out mid
        ListNode* mid = slow;
        ListNode* newHead = mid->next;
        mid->next = NULL;
        ListNode* head1 = reverse(newHead);

        //now we have to compare both the linked list
        ListNode* t1 = head;
        ListNode* t2 = head1;
        while(t1 && t2) {
            if(t1->val != t2->val) return false;
            t1 = t1->next;
            t2 = t2->next;
        }
        if((t1 && t2) || (t1 == NULL || t2 == NULL)) return true;

        return false;
    }
};
