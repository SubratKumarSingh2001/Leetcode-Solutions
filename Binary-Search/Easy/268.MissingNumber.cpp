class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Approach:1
        // TC: O(nlogn), due to sort funtion, SC: O(n)
        // we will sort the array
        sort(nums.begin(), nums.end());
        int start=0, end=nums.size()-1;
        int mid = start + (end-start)/2;
        while(start < end) {
            if(nums[mid] == mid) {
                start = mid+1;
            }
            else {
                //we dont know whether the element can be a missing number
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        if(nums[start] != start) {
            return start;
        }
        
        //if already sorted then just return the size of an array
        return nums.size();

        //Approach:2
        //TC: O(n), SC: O(n)
        int n = nums.size();
        vector<int> ans(n+1, -1); //because we are checking which ele is missing
        for(int i=0; i<nums.size(); i++) {
            ans[nums[i]] = 0;
        }
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] == -1) {
                return i;
            } 
        }
        return -1;
    }
};
