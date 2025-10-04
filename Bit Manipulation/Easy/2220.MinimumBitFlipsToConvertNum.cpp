class Solution {
public:
    int minBitFlips(int start, int goal) {
        //TC: O(no.of setbits), SC: O(1)
        int val = start ^ goal;
        //now count the set bits
        int cnt = 0;
        while(val) {
            //Brian Kernighan's Algorithm
            val = val & (val-1);
            cnt++;
        }
        return cnt;
    }
};
