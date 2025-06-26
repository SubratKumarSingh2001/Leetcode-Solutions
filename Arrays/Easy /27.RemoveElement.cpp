class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //Brute Force
        //TC: O(n), Sc: O(n)
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != val) {
                ans.push_back(nums[i]);
            }
        }
        //we have to change the original array
        nums = ans;
        
        return nums.size();

        //Optimal Solution: Two-pointers Approach
        if(nums.size() == 0) return 0;
        
        int i=0;
        for(int j=1; j<nums.size(); j++) {
            if((nums[i] == val) && (nums[j] != val)) {
                swap(nums[i], nums[j]);
                i++;
            }
            else if(nums[i] != val) {
                i++;
            }
        }
        if (nums[i] != val) i++;
        return i;
    }
};
