class Solution {
public:
    bool search(vector<int> &arr, int x) {
        int s=0, e=arr.size()-1;
        int m = s +(e-s)/2;
        while(s <= e) {
            if(arr[m] == x) return true;
            else if(arr[m] > x) {
                e = m-1;
            }
            else {
                s = m+1;
            }
            m = s +(e-s)/2;
        }
        return false;
    }

    int findKthPositive(vector<int>& arr, int k) {
        //TC: O(k*logn), SC: O(k)
        vector<int> nums;
        int j=1;
        while(nums.size() < k) {
            if(!search(arr, j)) {
                nums.push_back(j);
            }
            j++;
        }
        return nums[k-1];
        
        //TC: O(logn), SC: O(1)
        int start=0, end=arr.size()-1;
        int mid = start + (end-start)/2;
        while(start <= end) {
            int missing = arr[mid] - (mid+1);
            if(missing < k) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return end+k+1; //low+k also
    }
};
