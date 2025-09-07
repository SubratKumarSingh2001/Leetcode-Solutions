class Solution {
public:
    int minOperations(vector<int>& nums) {
        //Greedy Approach, TC: O(n), SC: O(1)
        // We know the answer will ve either 0 or 1, But Why?
        // When all the elements are same means our target was to make all the elements same, but all 
        // the elements are already same, so in case the minimum no.of operation will be 0.
        // But if we found non distint elements in that case we need to find the minimum no.of 
        // operation to make all the elements same, that can be possible by finding the bitwise and of
        // all elements and assign that value to all the elements, it like considering the whole array
        // as subarray for minimum operation 
        int cnt = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                cnt++;
                break;
            }
        }
        return cnt;
    }
};
