class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute Force
        //TC: O(n^2), SC: O(1)
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {};

        //Optimal Solution: Hashmap
        //TC: O(n), SC: O(n)
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++) {
            int diff = target - nums[i]; //we will find diff in the hashmap
            if(mpp.find(diff) != mpp.end()) {
               //if we got the difference means i+mpp(diff) == target is present in map
               return {i, mpp[diff]};
            }
            //we will insert all element in map along wiht index
            mpp[nums[i]] = i;
        }
        return {};
    }
};
