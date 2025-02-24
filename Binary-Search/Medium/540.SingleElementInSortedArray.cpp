class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //Brute force, TC: O(n), SC: O(1)
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;

        //Optimal Approach: Binary Search, TC: O(logn), SC: O(1);
        int start = 0, end = nums.size()-1;
        int mid  = start + (end - start)/2;
        while(start <= end) {
            if(start == end) {
                return nums[start];
            }
            if(mid % 2 == 0) {
                if(nums[mid] == nums[mid-1]) {
                    end = mid - 2;
                }
                else {
                    /*
                    as required ans is present at even index so we dontwant to 
                    loose mid index
                    */
                    start = mid;
                }
            }
            else {
                if(nums[mid] == nums[mid+1]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            mid = start + (end - start)/2;
        }
        return -1;
    }
};
