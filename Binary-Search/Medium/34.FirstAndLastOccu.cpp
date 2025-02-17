class Solution {
public:
    int firstOccurence(vector<int> arr, int target) {
        //Brute Force: O(logn), SC:O(1)
        int start=0, end=arr.size()-1;
        int mid = start + (end-start)/2;
        int ans1 =-1;
        while(start<=end) {
            if(target == arr[mid]) {
                ans1 = mid;
                end =mid-1;
            }
            else if(target < arr[mid]) {
                end =mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return ans1;
    }
    int lastOccurence(vector<int> arr, int target) {
        int start=0, end=arr.size()-1;
        int mid = start + (end-start)/2;
        int ans2 =-1;
        while(start<=end) {
            if(target == arr[mid]) {
                ans2 = mid;
                start=mid+1;
            }
            else if(target < arr[mid]) {
                end =mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return ans2;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1 = firstOccurence(nums, target);
        int ans2 = lastOccurence(nums, target);
        return {ans1, ans2};
    }
};
