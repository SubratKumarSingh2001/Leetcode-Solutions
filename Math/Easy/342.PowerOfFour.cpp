class Solution {
public:
    bool isPowerOfFour(int n) {
        //Approach:1 TC: O(logn), SC: O(1);
        int i=0;
        while(n) {
            if(pow(4,i) == n) {
                return true;
            }
            else if(pow(4,i) > n) {
                break;
            }
            else {
                i++;
            }
        }
        return false;

        //Approach:2 TC: O(logn), SC: O(1)
        while(n) {
            if(n == 1)  return true;
            if(n % 4 != 0) break;
            n /= 4;
        }
        return false;  
    }
};
