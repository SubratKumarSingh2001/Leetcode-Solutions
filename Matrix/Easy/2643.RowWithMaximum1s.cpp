class Solution {
public:
    //TC: O(m), SC: O(1)
    int count1(vector<int> &nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
            }
        }
        return count;
    }

    //TC o(mlogm), SC: O(1);
    int count2(vector<int> &nums, int cols) {
        sort(nums.begin(), nums.end());
        int s=0, e=nums.size()-1;
        int m = s +(e-s)/2;
        int ans = -1;
        while(s <= e) {
            if(nums[m] == 1) {
                ans = m;
                e = m-1;
            }
            else {
                s = m+1;
            }
            m = s + (e-s)/2;
        }
        return (ans == -1) ? 0 : cols-ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        /*Brute Force if we use count1 func then TC: O(n*m), SC: O(1)*/
        //Bad Solution, TC: O(n*mlogm), SC: O(1)
        int prevCount=0, row=0, cols=mat[0].size();
        for(int i=0; i<mat.size(); i++) {
            int newCount = count2(mat[i], cols);
            if(newCount > prevCount) {
                prevCount = newCount;
                row = i;
            }
        }
        return {row, prevCount};
    }
};
