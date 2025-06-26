class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Optimal Solution: Two Pointers Approach
        //TC: O(n), SC: O(1)
        int i=0;
        for(int j=1; j<nums.size(); j++) {
            if((nums[i] == 0) && (nums[j] != 0)) {
                swap(nums[i], nums[j]);
                i++;
            }
            else if(nums[i] != 0) {
                i++;
            }
        }
    }
};
