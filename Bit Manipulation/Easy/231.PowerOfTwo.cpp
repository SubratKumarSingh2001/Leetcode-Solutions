class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*Using Bit Manipulation: The number which are power of two have only one set bit count*/
        //TC: O(logn), SC: O(1)
        if( n < 0) return false;
        int cnt = 0;
        while(n) {
            n = n & (n-1);
            cnt++;
        }
        if(cnt == 1) return true;
        else return false;

        //Another way, TC: O(1), SC: O(1)
        if(n <= 0) return false;
        if((n & (n-1)) == 0) return true;
        else return false;
    }
};
