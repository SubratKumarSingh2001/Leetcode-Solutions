class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Brute Force Method : Not In-place method 
        //TC: O(n), SC: 0(n) (For In-place the SC should be O(1))
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != ans[ans.size()-1]) {
                ans.push_back(nums[i]);
            }
        }
        nums = ans; // this make changes in original array i.e in-place algo

        return ans.size();
    }
};
