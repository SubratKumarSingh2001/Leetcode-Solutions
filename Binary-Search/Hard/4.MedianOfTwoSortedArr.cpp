class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Brute Force, Merge two sorted array into another array
        //TC: O(m+n), SC: O(m+n)
        vector<int> ans;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()) {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()) {
            ans.push_back(nums2[j]);
            j++;
        }

        //now we will check the size of an ans array
        double median;
        int n = ans.size();
        if(ans.size()%2 == 0) {
            median = (double)(ans[(n/2)-1] + ans[n/2])/2;
        }
        else {
            median = (double)ans[(n-1)/2];
        }
        return median;

        //Better Soltuion, reducing space 
        //TC: O(m+n), SC: O(1) 
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int idx2 = (n1 + n2)/2;
        int idx1 = idx2-1;
        int i=0, j=0;
        int ele1 =-1, ele2 = -1;
        int cnt = 0;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                if(cnt == idx1) ele1 = nums1[i];
                if(cnt == idx2) ele2 = nums1[i];
                cnt++;
                i++;
            }
            else {
                if(cnt == idx1) ele1 = nums2[j];
                if(cnt == idx2) ele2 = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<nums1.size()) {
            if(cnt == idx1) ele1 = nums1[i];
            if(cnt == idx2) ele2 = nums1[i];
            cnt++;
            i++;
        }
        while(j<nums2.size()) {
            if(cnt == idx1) ele1 = nums2[j];
            if(cnt == idx2) ele2 = nums2[j];
            cnt++;
            j++;
        }

        double median;
        if(n%2 == 0) {
            median = (double)(ele1 + ele2)/2;
        }
        else {
            median = (double)ele2;
        }

        return median;

        //Optimal Solution, Need more Revision, Binary Search
        //TC: O(log(min(n1,n2))), SC: O(1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        //we will apply binary search on smaller array
        if(n1 > n2)  return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int leftEle = (n1 + n2 + 1)/2; //how many elements should be in left portion
        int start = 0, end = n1;// as we can take 0 element or till size of n1 element
        int mid1 = start + (end-start)/2;
        int mid2 = leftEle - mid1;
        while(start <= end) {
            //Assigning the values of l1, l2, r1 and r2
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1-1 >= 0) l1 = nums1[mid1-1]; //check not accessing invalid index
            if(mid2-1 >= 0) l2 = nums2[mid2-1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2)  r2 = nums2[mid2];

            //when we have got our desired l1 l2, r1, r2 we will find median if n even/odd
            if(l1 <= r2 && l2 <= r1) {
                if(n%2 == 0) {
                    return (double)(max(l1, l2) + min(r1, r2))/2.0; 
                }
                else {
                    return (double)max(l1, l2);
                }
            }

            //if uppr doesnt fulfill we will eliminate the left or right half of small arr
            if(l1 < r2) {
                start = mid1+1;
            }
            else {
                end = mid1-1;
            }
            mid1 = start + (end-start)/2;
            mid2 = leftEle - mid1;
        }
        return 0;
    }
};
