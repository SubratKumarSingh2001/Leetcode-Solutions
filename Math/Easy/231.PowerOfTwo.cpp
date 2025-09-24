class Solution {
public:
    bool isPowerOfTwo(int n) {
        //Approach:1 TC: O(logn) SC: O(1)
        int i=0;
        while(n) {
            if(pow(2,i) == n) {
                return true;
            }
            else if(pow(2,i) > n) {
                break;
            }
            else {
                i++;
            }
        }
        return false;

        //Approach:2 TC: O(logn) SC: O(1) 
        while(n) {
            if(n == 1)  return true;
            if(n % 2 != 0) break;
            n /= 2;
        }
        return false;

        //Approwch:3 Bit Manipulation 
        //power of 2 means 2^k where k >= 0 1,2,4,8,16..... so negative no cant be raised in power of 2. So if any -ve no return false 
        if(n <= 0) return false;
        return (n & (n-1)) == 0 ? true : false;
    }
};
