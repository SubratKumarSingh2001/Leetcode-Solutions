class Solution {
public:
    bool check(vector<int>& nums) {
        //TC: O(n), SC: O(1)
        int cnt=0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] > nums[i]) {
                cnt++;
            }
        }
        if(nums[nums.size()-1] > nums[0]) {
            cnt++;
        }

        return (cnt <= 1) ? true : false;
    }
};
