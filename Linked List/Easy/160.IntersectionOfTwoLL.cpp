class Solution {
public:
    ListNode* intersectionPoint(ListNode* headA, ListNode* headB, int diff) {
        //first we will move bigger lenght linked diff step ahead
        ListNode* tempA = headA;
        while(diff--) {
            tempA= tempA->next;
        }
        ListNode* tempB = headB;
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Approach:1 Brute Force
        /*Using nested loops as for each element of one linked list traverse all ele of
        the second linked list
        */
        //TC: O(n1*n2), where n1 and n2 are the length of resp. linked list, SC: O(1)
        while(headA) {
            ListNode* temp = headB;
            while(temp) {
                if(temp == headA) return temp;
                temp = temp->next;
            }
            headA = headA->next;
        }
        return NULL;

        //Approach:2 
        /*Finding the length of both the nodes and then check the difference of both 
        len decide how much nodes we need to move the longer linked list so that they 
        can collide at same node
        */
        //TC: O(n2+2n1) where n1 and n2 are length of linked list resp. SC: O(1)
        int lenA = 0, lenB=0;
        ListNode* temp = headA;
        while(temp) {
            lenA++;
            temp = temp->next;
        }
        temp = headB;
        while(temp) {
            lenB++;
            temp = temp->next;
        }
        //compare the length of both linked list
        if(lenA > lenB) {
            return intersectionPoint(headA, headB, lenA-lenB);
        }
        else {
            return intersectionPoint(headB, headA, lenB-lenA);
        }
        return NULL;

        //Approach:3 Optimal Solution
        /*TC: Because for the worse case when no intersection point boht of temp ptr
        traverse both the linked list, i.e O(n1+n2), SC: O(1)
        */
        //if either of linked list is empty
        if(headA == NULL || headB == NULL) return NULL;
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA != tempB) {
            //moving one node ahead
            tempA = tempA->next;
            tempB = tempB->next;

            /*when both are equal, this case will work when no intersection too, when
            both the temp pointers are null*/
            if(tempA == tempB) return tempA;

            //when either of temp pointer is null
            if(tempA == NULL) tempA = headB;
            if(tempB == NULL) tempB = headA;
        }
        //when both the linked are same means single linked list start is intersect point
        return tempA; //can return tempB also
    }
};
