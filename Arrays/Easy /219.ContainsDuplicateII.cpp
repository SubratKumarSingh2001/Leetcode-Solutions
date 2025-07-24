class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //Brute Force, TC: O(n^2), SC: O(1)
        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    if(abs(i-j) <= k) return true;
                    else continue;
                }
            }
        }
        return false;

        //Optimal Solution, Hashing 
        //TC: O(n), SC: O(n)
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++) {
            if(mpp.find(nums[i]) != mpp.end()) {
                if(abs(i - mpp[nums[i]]) <= k) {
                    return true;
                }
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};
