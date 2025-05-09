class Solution {
public:
    ListNode* getKthNode(ListNode* temp, int k) {
        ListNode* curr = temp;
        int i=1;
        while(curr && i < k) {
            curr = curr->next;
            i++;
        }
        return curr;
    }

    ListNode* reverseTheLL(ListNode* temp) {
        ListNode* prev = NULL;
        ListNode* curr = temp;
        while(curr) {
            ListNode* forward = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        //TC: O(k) + O(k) = O(2k) overall the loop runs till O(n/k) i.e = O(n)
        //SC: O(1)
        //explictly handle the edge case, when no nodes and single node 
        if(head == NULL || head->next == NULL) return head;

        //for more than one nodes
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp) {
            //first find the kth node, node till where we have to reverse 
            ListNode* kthNode = getKthNode(temp,k);

            /*there could be possibility that kthNode is Null, means no formation 
            of k-group of nodes 
            */
            if(kthNode == NULL) {
                //means the group cant be formed 
                prevNode->next = temp;
                break;
            }
            //If not Null means formation of k-group of nodes
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            //now we have separated the kth-group nodes, time to revese it 
            reverseTheLL(temp);
            //now if the reversing kth-group LL is first LL then update head
            if(temp == head) {
                head = kthNode;
            }
            else {
                /*when the fist kth-group is reversed after that we need to link the 
                previous groups with curr reversed kth groups
                */
                prevNode->next = kthNode;
            }
            /*now we have to join the previous kth-reverse group with next kth- reversed
            group and so on */
            prevNode = temp;
            temp = nextNode;
        }
        //now return the head of updated linked list
        return head;
    }
};
