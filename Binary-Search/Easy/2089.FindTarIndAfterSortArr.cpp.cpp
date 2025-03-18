class Solution {
public:
    int firstOccur(vector<int> &nums, int x) {
        //TC: O(logn), SC: O(1)
        int s=0, e=nums.size()-1;
        int m = s + (e-s)/2;
        int first = -1;
        while(s <= e) {
            if(nums[m] == x) {
                first = m;
                e = m-1;
            }
            else if(nums[m] > x ) e = m-1;
            else s = m+1;
            m = s + (e-s)/2;
        }

        return first;
    }

    int lastOccur(vector<int> &nums, int x) {
        //TC: O(logn), SC: O(1)
        int s=0, e=nums.size()-1;
        int m = s + (e-s)/2;
        int last = -1;
        while(s <= e) {
            if(nums[m] == x) {
                last = m;
                s = m+1;
            }
            else if(nums[m] > x ) e = m-1;
            else s = m+1;
            m = s + (e-s)/2;
        }
        
        return last;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        /* when we use an inbuilt sort function which is made up of insertion, 
        quick, and merge sort for the best and average case the inbuilt sort uses 
        quick sort so the space complexity is O(logn) but for the worse case the inbuilt 
        sort function, sort the array using merge sort which takes an extra space to 
        divide and conquer, therefor the SC is O(n)
        */
        //Brute Force, TC: O(nlogn), SC: O(n)
        vector<int> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                result.push_back(i);
            }
        }
        return result;

        //Approach:2
        //TC: O(n*logn), TC: O(n);
        sort(nums.begin(), nums.end()); //TC: O(n*logn), SC: O(n)
        int first = firstOccur(nums, target);
        int last = lastOccur(nums, target);
        vector<int> res;
        if(first == -1 && last == -1) return res;
    
        for(int i=first; i<=last; i++) {
            res.push_back(i);
        }

        return res;

        //Approach:3 Optimal Solution
        //TC: O(n), SC:  O(n)
        int small=0, large=0;
        for (int i = 0; i < nums.size(); i++) {  
            if (nums[i] < target) small++;
            else if (nums[i] > target) large++;
        }

        // Storing indices in a vector
        vector<int> ans;
        for (int i = small; i < nums.size() - large; i++) { 
            ans.push_back(i);
        }

        return ans;
    }
};
