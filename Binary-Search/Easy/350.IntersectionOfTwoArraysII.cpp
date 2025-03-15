class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //Appraoch:1 Brute Force, Two Pointers
        //TC: O(n*logn + m*logm), SC: O(min(m,n))
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;

        //Approach:2 Optimal Solution will write... 
    }
};
