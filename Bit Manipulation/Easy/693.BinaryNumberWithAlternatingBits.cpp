class Solution {
public:
    bool hasAlternatingBits(int n) {
        //TC: O(n), SC: O(1)
        while(n) {
            int bit1 = n & 1;
            n = n >> 1;
            int bit2 = n & 1;
            if(bit1 == bit2) return false;
        }
        return true;
    }
};
