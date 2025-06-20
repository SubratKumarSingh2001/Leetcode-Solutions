class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //TC : Overall is O(n), where n is the length of linked list
        //SC: O(k), where k is no. of critical points 
        vector<int> ans; //we can exclude this, can write without any extra space
        int cnt=1;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* nextNode = curr->next;
        while(nextNode) {
            //inc. the cnt value, which tell which no. node we are standing (1st node etc)
            cnt++;
            //Critical Point: Local Maxima and Local Minima
            if(((curr->val > prev->val) && (curr->val > nextNode->val)) ||
            ((curr->val < prev->val) && (curr->val < nextNode->val))) {
                ans.push_back(cnt);
            }
            prev = curr;
            curr = nextNode;
            nextNode = curr->next;
        }

        //now we have an array of all critical points in the linked list
        //if the size of an array is not empty then min and max value will be there
        if(ans.size() >=2) {
            //here min distance b/w any two disticnt critical points
            int minDist = INT_MAX; 
            for(int i=1; i<ans.size(); i++) {
                minDist = min(minDist, ans[i]-ans[i-1]);
            }
            return {minDist, ans[ans.size()-1]-ans[0]/*maxDist*/};
        }
        else {
            return {-1,-1};
        }

        return {-1,-1};
    }
};
