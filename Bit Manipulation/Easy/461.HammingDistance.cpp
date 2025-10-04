class Solution {
public:
    int hammingDistance(int x, int y) {
        //TC: O(no.of set bits), SC: O(1)
        int val = x ^ y;
        //now count the set bits
        int cnt = 0;
        while(val) {
            val = val & (val-1);
            cnt++;
        }
        return cnt;
    }
};
