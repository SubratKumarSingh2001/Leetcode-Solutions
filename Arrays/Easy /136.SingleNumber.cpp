class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Approach:1 Brute Force TC: O(n*logn), SC: O(n)
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i=i+2) {
            if(nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        return nums[nums.size()-1];

        // Approach:2 Binary Search 
        //TC: O(n*logn), SC: O(n)
        sort(nums.begin(), nums.end());
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
                    as required ans is present at even index so we dont want to 
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

        //Approah:3 Optimal Solution TC: O(n), SC: O(1)
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
