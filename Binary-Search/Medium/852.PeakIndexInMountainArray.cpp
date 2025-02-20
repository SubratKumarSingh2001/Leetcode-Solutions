class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //Brute Force, TC: O(n) SC: O(1)
        int max = INT_MIN;
        int index = -1;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] > max) {
                max = arr[i];
                index = i;
            }
        }
        return index;

        //Optimal Approach, Binary Search, TC: O(logn) SC: o(1)
        int start = 0, end = arr.size()-1;
        int mid = start + (end-start)/2;
        while(start <= end) {
            if(start == end) {
                return start;
            }
            else if(arr[mid] < arr[mid+1]) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
            mid = start + (end-start)/2;
        } 
        return -1;
    }
};
