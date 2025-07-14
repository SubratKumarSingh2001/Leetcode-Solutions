class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Brute Force: Using the extra space
        //TC: O(m+n), SC: O(m+n) 
        vector<int> ans;
        int i=0, j=0;
        while(i<m && j<n) {
            if((ans.empty() && nums1[i] <= nums2[j]) || (nums1[i] <= nums2[j])) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m) {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n) {
            ans.push_back(nums2[j]);
            j++;
        }
        nums1 = ans;

        //Optimal Solution
        //TC: O(m+n), SC: O(1)
        if(nums2.empty()) return;
        int i=m-1, j=n-1, lst_idx = nums1.size()-1;
        while(i>=0 && j>=0) {
            if(nums1[i] >= nums2[j]) {
                nums1[lst_idx] = nums1[i];
                i--;
            }
            else {
                nums1[lst_idx] = nums2[j];
                j--;
            }
            lst_idx--;
        }
        while(j>=0) {
            nums1[j] = nums2[j];
            j--;
        }
    }
}; 
