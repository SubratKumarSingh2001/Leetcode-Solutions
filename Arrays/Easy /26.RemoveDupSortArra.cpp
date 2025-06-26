class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Brute Force: Not In-place 
        //TC: O(n), SC: O(n)
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != ans[ans.size()-1]) {
                ans.push_back(nums[i]);
            }
        }
        //we have to modify original array
        nums = ans
        return nums.size();

        //Optimal Solutio: Two-Pointers Approach
        //TC: O(n), SC: O(1)
        int i=0, j=1; //i: hold the last unique element and j: traverse through the array
        while(j < nums.size()) {
            if(nums[i] != nums[j]) {
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};
