class Solution {
public:
    int search(vector<int>& nums, int target) {
        //TC: O(logn) SC: 0(1)
        int start=0, end= nums.size()-1;
        int mid = start + (end-start)/2;
        while(start <= end) {
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }
};
