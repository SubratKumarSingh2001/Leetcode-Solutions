class Solution {
public:
    bool isPerfectSquare(int num) {
        //TC: O(logn), SC: O(1)
        int start = 0, end = num;
        /* here we had use long long because when we multiply large mid value with
        same mid value it may go out of integer range so we have use long long of 8 
        bytes  i.e 64 bits which can store the mid*mid large valu considering the 
        integer range 
        */
        long long mid = start + (end-start)/2;
        while(start <= end) {
            if(mid*mid == num) {
                return true;
            }
            else if(mid*mid > num) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return false;
    }
};
