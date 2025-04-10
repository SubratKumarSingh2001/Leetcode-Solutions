class Solution {
public:
    int maximumCount(vector<int>& nums) {
        //Brute Force, TC: O(n), SC: O(1)
        int pos=0, neg=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) pos++;
            else if(nums[i] < 0) neg++;
        }
        return max(pos, neg);

        //Optimal Solution, Binary Search
        //TC: O(logn), SC: O(1)
        int start=0, end=nums.size()-1;
        int mid = start + (end-start)/2;
        int neg=-1;
        while(start <= end) {
            if(nums[mid] < 0) {
                neg = mid;
                start = mid+1;
            }
            else {
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }

        int pos=-1;
        start=0, end= nums.size()-1;
        mid = start + (end-start)/2;
        while(start <= end) {
            if(nums[mid] > 0) {
                pos = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        
        //here pos and neg are assigned -1 because they hold index value of nums array
        start=0, end=nums.size()-1;
        if(pos != -1 && neg != -1) return max(neg+start+1, end-pos+1);
        if(pos != -1) return end-pos+1;
        if(neg != -1) return neg+1;
        return 0;
    }
};
