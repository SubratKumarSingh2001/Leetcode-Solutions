class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Brute Force, TC: O(n^3), SC: O(1)
        //Finding all the subarrays same as Brute Force of Maximum Sum Subarray

        //Better Solution, TC: O(n^2), Sc: O(1)
        int maxProduct = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            int product = 1;
            for(int j=i; j<nums.size(); j++) {
                product *= nums[j];
                maxProduct = max(maxProduct, product);
            }
        }
        return maxProduct;

        //optimal Solution : Obserrvation (Revsist this problem again)
        long long maxi = INT_MIN, prefix = 1, sufix = 1;
        for(int i=0; i<nums.size(); i++) {
            //first we will evaluate the prefix and sufix sum
            prefix *= nums[i];
            sufix *= nums[nums.size()-i-1];

            //now we will find the max of prefix and sufix and then compare with max
            maxi = max(maxi, max(prefix, sufix));

            /*When there are case when there are 0s in arrays means that the maximum 
            product subarray wont contain 0 in it. So we will dvide the array into subarr-
            ary without zeros and find the product
            */
            if(prefix == 0) prefix = 1;
            if(sufix == 0) sufix = 1;
        }
        return maxi;
    } 
};
