class Solution {
public:
    int possible(vector<int>& nums, int minSum) {
        int currSum = minSum, possValK=0;
        int i=0;
        while(i < nums.size()) {
            if(currSum >= nums[i]) {
                currSum -= nums[i];
                i++;
            }
            else {
                possValK++;
                currSum = minSum;
            }
        }
        /*at last we have to increase the possValK by 1 because before adding last one 
        we ended the loop as we haven't updated the number of possValK to allocate all 
        the subarrays
        */
        return ++possValK;
        // if(possValK <= k) return true;
    }

    int sum(vector<int>& nums) {
        int sum=0;
        for(auto num : nums) {
            sum += num;
        }
        return sum; 
    }

    int splitArray(vector<int>& nums, int k) {
        //Brute Force, TC: O((max-min+1)*n) (where n is the size of array) ,SC: O(1)
        if(k > nums.size())  return -1;
        
        int min = *max_element(nums.begin(), nums.end());
        int max = sum(nums);
        for(int i=min; i<=max; i++) {
            if(possible(nums, i, k)) {
                return i;
            }
        }
        return -1;

        //Optimal Solution, Binary Search 
        //TC: O(log(max-min+1)*n) (where n is the size of array) ,SC: O(1)
        int start=min, end=max;
        int mid = start + (end-start)/2;
        int minSum = -1;
        while(start <= end) {
            if(possible(nums, mid) <= k) {
                minSum = mid;
                end = mid-1; 
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return minSum;
    }
};
