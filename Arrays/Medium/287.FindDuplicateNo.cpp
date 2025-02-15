class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //brute force method
        //TC: O(nlogn), SC: O(n) (Worse Case the space complexity will be O(n))
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] == nums[i+1]) {
                return nums[i];
            }
        }
        return -1;

        //Optimal Approach:1
        //TC: O(n), SC: O(1)
        int ans = -1;
        for(int i=0; i<nums.size(); i++) {
            int index = abs(nums[i]);
            if(nums[index] < 0) {
                ans = index;
                break;
            }
            else {
                nums[index] *= ans;
            }
        }
        return ans;

        //Optimal Approach:2
        //TC: O(n), SC: O(1)
        while(nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};
