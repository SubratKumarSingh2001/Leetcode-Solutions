class Solution {
public:
    int pivot(vector<int>& nums, int start, int end) {
        int mid = start + (end-start)/2;
        while(start <= end) {
            if(mid+1<=end && nums[mid]>nums[mid+1]) {
                return mid;
            }
            else if(mid-1>=start && nums[mid]<nums[mid-1]) {
                return mid-1;
            }
            else if(nums[start] > nums[mid]) {
                end = mid-1;
            }
            else if(nums[start] < nums[mid]) { //no duplicate values
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        //TC: O(logn), SC: O(1)
        int start=0, end=nums.size()-1;
        //if array is already sorted then very first element will be small than last ele
        if(nums[start] < nums[end]) {
            return nums[0];
        }
        else if(start == end) {
            return nums[start];
        }
        int pivotIndex = pivot(nums, start, end);

        return nums[pivotIndex+1];
    }
};
