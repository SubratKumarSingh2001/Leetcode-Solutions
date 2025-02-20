class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //Optimal Approach, Binary Search, TC: O(logn) SC: o(1)
        int start = 0, end = nums.size()-1;
        int mid = start + (end-start)/2;
        while(start <= end) {
            if(start == end) {
                return start;
            }
            else if(nums[mid] < nums[mid+1]) {
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
