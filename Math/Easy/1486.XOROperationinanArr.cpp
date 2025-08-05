class Solution {
public:
    int xorOperation(int n, int start) {
        //TC: O(n), SC: O(1)
        int xorVal = 0, val = 0;
        for(int i=0; i<n; i++) {
            val = start + 2 * i;
            xorVal = xorVal ^ val;
        }
        return xorVal;
    }
};
