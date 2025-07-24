class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //Brute force : TC: O(n^2), SC: O(1)
        for(int i=0; i<nums.size(); i++) {
            int search=nums[i],cnt=0;
            for(int j=0; j<nums.size(); j++) {
                if(nums[j] == search) cnt++;
            }
            if(cnt > 1) return true;
        }
        return false;

        //Better Solution: Sorting 
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;

        //Optimal Solution : Hashing 
        //TC: O(n), SC: O(n)
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++) {
            mpp[nums[i]]++; //storing in map
        }
        //fetching from map
        for(auto it : mpp) {
            if(it.second > 1) return true;
        }
        return false;
    }
};
