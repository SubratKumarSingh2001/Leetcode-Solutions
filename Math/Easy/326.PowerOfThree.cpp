class Solution {
public:
    bool isPowerOfThree(int n) {
        //Approach:1 TC: O(logn), SC: O(1);
        int i=0;
        while(n) {
            if(pow(3,i) == n) {
                return true;
            }
            else if(pow(3,i) > n) {
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
            if(n % 3 != 0) break;
            n /= 3;
        }
        return false;  
    }
};
