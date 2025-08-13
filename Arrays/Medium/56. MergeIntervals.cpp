class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //Optimal Soluiton, TC: O(nlogn) + O(n), SC: O(n) 
        vector<vector<int>> ans;
        //we will first sort the array because all the intervals[i] having start smaller will come first
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); i++) {
            //now when are add an subinterval to the ans, whena ns is empty or ans end is less then current interval[i][0]
            if(ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else {
                // when the intervals[i][0] is less than the ans.back()[1]
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
