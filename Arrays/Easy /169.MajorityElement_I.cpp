class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Brute Force
        //TC: O(n^2) SC: O(1)
        // for(int i=0; i<nums.size(); i++) {
        //     int count=1;
        //     for(int j=i+1; j<nums.size(); j++) {
        //         if(nums[i] == nums[j]) {
        //             count++;
        //         }
        //     }
        //     if(count>(nums.size()/2)) {
        //         return nums[i];
        //     }
        // }
        // return -1;

        //Optimal Solution : Boyers-More Voting Algorithm (IMPORTANT)
        //TC: O(n), SC: O(1)
        int candidate=0, count=0;
        for(int i=0; i<nums.size(); i++) {
            if(count == 0) {
                candidate = nums[i];
                count++;
            }
            else if(nums[i] == candidate) {
                count++;
            }
            else {
                count--;
            }
        }

        /*
        now we have got the potential majority algorithm, check whether it is 
        actual majority element or not
        */
        count=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == candidate) {
                count++;
            }
        }
        if(count > (nums.size()/2)) {
            return candidate;
        }
        else {
            return -1;
        }
    }
};
