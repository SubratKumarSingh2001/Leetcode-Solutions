class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Brute Forc: O(n^2), SC: O(1)
        int cntSubArr = 0;
        for(int i=0; i<nums.size(); i++) {
            long long sum = 0;
            for(int j=i; j<nums.size(); j++) {
                sum += nums[j];
                if(sum == k) cntSubArr++; //if(sum>k) no (size>k) bcz nums have -ve ele
            }
        }
        return cntSubArr;

        //Optimal Solution: Hashing and PrefixSum
        //TC: O(n*logn) if we are using map STL then, if we use unordered_map O(n*1)/O(n^2)
        //SC: O(1)
        long long preSum = 0;
        int cntSubArr = 0;
        unordered_map<long long, int> mpp;
        mpp[0] = 1;
        for(int i=0; i<nums.size(); i++) {
            //Phele hum prefix sum nikalenge i-index tak
            preSum += nums[i];

            /*Aab hame till index i tak sare subarraay dhoondne hai jiska sum k ho, uske
            liye hum preSum-k dhoondenge agar wo hai means till index i subarray bhi hai
            but subarray 1,2 ya aur bhi ho skate hai hum kya krenge sare prefix sum ke
            cnt ko map me store krenge jitna baar bhi ayega*/
            long long rem = preSum - k;

            //now we will add the cnt with the count of "rem" stored in map
            cntSubArr += mpp[rem];

            /*if the "rem" encounterd again we will increase it value because it been 
            encountered again til the ith index where prefix sum has been evaluated*/
            mpp[preSum]++;
        }
        return cntSubArr;
    }
};
