class Solution {
public: 
    int sum(vector<int> &nums, int divisor) {
        int sum=0;
        for(int i=0; i<nums.size(); i++) {
            sum += ceil((double)nums[i]/divisor);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        //Brute Force 
        /*To find the max element no.of comparsions n 
        Therefore, TC: O(maxEle*n) + O(n) = O(maxEle*n), SC: O(1)
        */
        // int maxEle = *max_element(nums.begin(), nums.end());
        // int divisor=1, sum=0;
        // while(divisor <= maxEle) {
        //     sum=0;
        //     for(int i=0; i<nums.size(); i++) {
        //         sum += ceil((double)nums[i]/divisor);
        //         if(sum > threshold) break;
        //     }
        //     if(sum <= threshold) return divisor;
        //     divisor++;
        // }
        // return -1;

        //Binary Search (Search Space)
        //TC: O(n*log(maxEle)), SC: O(1)
        int maxEle = *max_element(nums.begin(), nums.end());
        int start=1, end=maxEle;
        int divisor = start + (end-start)/2;
        int ans = -1;
        while(start <= end) {
            if(sum(nums, divisor) <= threshold) {
                ans = divisor;
                end = divisor-1;
            }
            else {
                start = divisor+1;
            }
            divisor = start + (end-start)/2;
        }
        return ans;
    }
};
