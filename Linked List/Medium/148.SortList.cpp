class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* ans = new ListNode(-1);
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode* temp3 = ans;
        while(temp1 && temp2) {
            if(temp1->val < temp2->val) {
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

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; //because for even we get second mid but want 1st mid
        while(fast && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        //Brute Force take all elements and put it in array and sort it
        //TC: O(n)+O(n*logn)+O(n) = O(n*logn) where n is no.of nodes in Linked List
        //SC: O(n)+O(n) = O(2n) = O(n) 
        //single and empty linked list
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        vector<int> ans;
        while(temp) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        //now apply the sort 
        sort(ans.begin(), ans.end());
        ListNode* newHead = new ListNode(-1);
        temp = newHead;
        for(int i=0; i<ans.size(); i++) {
            ListNode* newNode = new ListNode(ans[i]);
            temp->next = newNode;
            temp = temp->next;
        }

        return newHead->next;

        //Optimal Solution using merge sort
        //TC: O(n*logn), SC: O(1)
        //base case when we have single node or no node i.e head is null
        if(head == NULL || head->next == NULL) return head;

        //now we will find the mind using Tortoise-Hare Algo
        ListNode* mid = findMid(head);
        //right divide the linked list
        ListNode* rightHead = sortList(mid->next);
        //separate both the linked list
        mid->next = NULL;
        //left divide the linked list
        ListNode* leftHead = sortList(head);

        //now we will merge the sorted linked list
        ListNode* newHead = merge(leftHead, rightHead);

        return newHead;
    }
};
