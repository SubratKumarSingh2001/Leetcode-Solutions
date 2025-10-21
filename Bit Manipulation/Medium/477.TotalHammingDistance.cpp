class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        //Brute Force, TC: O(n^2), SC: O(1)
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                int val = nums[i] ^ nums[j];
                int cnt = 0;
                while(val) {
                    val = val & (val - 1);
                    cnt++;
                }
                sum += cnt;
            }
        }
        return sum;

        //Optimal Solution, Good Question 
        //TC: O(32*n), S: O(1)
        int cnt = 0;
        for(int i=0; i<32; i++) {
            int ones = 0;
            for(auto num : nums) {
                if((num >> i) & 1) ones++;
                /* num = num >> 1 wont work beause it create the copy of the element of array
                num = num >> 1 doesnt change the original array
                */
            }
            int zeros = nums.size() - ones;
            cnt += ones * zeros;
        }
        return cnt;
    }
};
