class Solution {
public:
    bool isUgly(int n) {
        //TC: O(logn), SC: O(1)
        if(n==0) return false;
        while(n > 1) {
            if(n%2 == 0) n = n/2;
            else if(n%3 == 0) n = n/3;
            else if(n%5 == 0) n = n/5;
            else break;
        }
        //at last if n==1 thne return true
        return n == 1 ? true : false;
    }
};
