class Solution {
public:
    int mySqrt(int x) {
        //TC: O(1)
        return pow(x, 0.5);

        //Without using any inbuilt exponent function: Binary Search
        //TC: O(logn), SC: O(1)
        int start = 0, end = x;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start <= end) {
            if(mid*mid == x) {
                return mid;
            }
            else if(mid*mid > x) {
                end = mid-1;
            }
            else {
                ans = mid;
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
}; 
