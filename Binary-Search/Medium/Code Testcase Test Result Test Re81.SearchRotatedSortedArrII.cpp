class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //Brute Force, TC: O(n), SC: O(1);
        // for(int num : nums) {
        //     if(num == target) return true;
        // }
        // return false; 

        //Optimal Solution, Binary Search
        //TC: O(logn), SC: O(1);
        int start=0, end=nums.size()-1;
        int mid= start + (end-start)/2;
        while(start <= end) {
            if(nums[mid] == target) {
                return true;
            }

            if(nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
                continue;
            }

            else if(nums[mid] >= nums[start]) {
                if(target >= nums[start] && target <= nums[mid]) {
                    end = mid-1;
                }
                else {
                    start = mid+1;
                }
            }
            else {
                if(target >= nums[mid] && target <= nums[end]) {
                    start = mid+1;
                }
                else {
                    end = mid-1;
                }
            }
            mid = start + (end-start)/2;
        }
        return false;;
    }
};
