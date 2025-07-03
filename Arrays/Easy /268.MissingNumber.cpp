class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Brute Force: Normal Sort Function
        //TC: O(nlogn), due to the sort algo, SC: O(1)
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != i) return i;
        }
        return nums.size();

        //Better Solution: Binary Search
        //TC: O(nlogn) + O(logn) = O((n+1)logn) = O(nlogn), SC: O(1) 
        sort(nums.begin(), nums.end());
        int start=0, end=nums.size()-1;
        while(start < end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == mid) {
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        //now single element we have to check the single ele hold missing or not
        if(nums[start] != start) return start;
        //if above if fails means nums[start] == start means array has no missing ele
        return nums.size();

        //Optimal Solution1: Summation
        /*Here the elements are present for 0->n where addition of 1 to n numbers 
        whill give us all elements sum (as 0 is present no issue) but one number is missing
        so we will find the summation of all the element and we will subtract the actual
        sum and sum we get, hence we will get the number which haven't be added from
        0->n that is the missing number
        */
        //TC: O(n), SC: O(1)
        int n = nums.size();
        int sum1 = n*(n+1)/2;
        int sum2 = 0;
        for(int i=0; i<nums.size(); i++) {
            sum2 += nums[i];
        }
        return sum1-sum2;

        //Optimal Solution2: XOR Opertion
        /*In summation case, We find the sum with the help of n(n+1)/2, which can exceeds
        the value of n too 10^5 for that case could give integer overflow for that we need
        to use different datatypes likes long long etc in XOR there is no such issue
        */
        //TC: O(n), SC: O(1)
        int xor1 = 0; //xor of all the elements in array
        int xor2 =0; //xor of first n elements
        for(int i=0; i<nums.size(); i++) {
            xor1 = xor1 ^ nums[i];
        }
        for(int i=1; i<=nums.size(); i++) {
            xor2 ^= i;
        }
        return (xor1 ^ xor2);

    }
};
