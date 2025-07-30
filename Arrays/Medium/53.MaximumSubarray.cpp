class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Brute Force : Finding all the subarrays and calculating the sum 
        //TC: O(n^3) approx n^3, SC: O(1)
        for(int i=0; i<nums.size(); i++) {
            for(int j=i; j<nums.size(); j++) {
                long long sum = 0;
                //now we will find the sum of all subarrays from i to j index and calc sum
                for(int k=i; k<=j; k++) {
                    sum += nums[k];
                    maxSum = max(maxSum, sum);
                }
            }
        }
        return maxSum;

        //Better solution, TC: O(n^2), SC: O(1)
        long long maxSum = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            long long sum = 0;
            for(int j=i; j<nums.size(); j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;  

        //optimal Solution : Kadane Algorithm
        //TC: O(n), SC: O(1)
        long long maxSum = INT_MIN;
        long long sum = 0;
        for(int i=0; i<nums.size(); i++) {
            //first we will evaluate the sum by addding on all the elements of array
            sum += nums[i];

            //now if the sum is greater than maxSum we will update the maxSum
            if(sum > maxSum) {
                maxSum = sum;
            } 

            /*now if the sum is negative that may hampper the answee (providng the max
            subarray sum and that subarray wont be part to that maximum subarray sum*/
            if(sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};
