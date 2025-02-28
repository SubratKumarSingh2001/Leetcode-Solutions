// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /* 
        To minimize the number of API calls will use Binary Search
        TC: O(logn), SC: O(1)
        */
        int start=1, end=n;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start <= end) {
            if(isBadVersion(mid)) {
                //First Store the latest bad version value and then find the first bad version if present in the left side of array
                ans = mid;
                end = mid - 1;
            }
            else {
                /*if the version is good version then bad version is present at the right side of the array as every version is developed based on previous versions, 
                Therefore the bad version won't present at the left side of the array
                */
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }
        return ans; 
    }
};
