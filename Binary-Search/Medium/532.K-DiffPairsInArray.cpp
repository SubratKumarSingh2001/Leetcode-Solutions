class Solution {
public:
    int search(vector<int>& nums, int target, int i) {
        //TC: O(nlogn), SC: O(n) as here the set consist of unique element upto size of n, so the worse the maximum no.of diff pairs could be equal to the size of an array
        int start=0, end=nums.size()-1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start <= end) {
            if(nums[mid] == target && i != mid) {
                ans = mid;
                start = mid+1;
            }    
            else if(nums[mid] > target) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<set<int>> ans;
        for(int i=0; i<nums.size(); i++) {
            int diff = nums[i] + k;
            if(search(nums, diff, i) != -1) {
                ans.insert({nums[i],diff});
            }
        }
        return ans.size();
    }
};
