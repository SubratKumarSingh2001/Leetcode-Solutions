class Solution {
public:
    bool isValidElement(vector<int> &arr2, int num, int d) {
        //TC: O(logn), SC: O(1)
        int start=0, end=arr2.size()-1;
        int mid = start + (end-start)/2;
        while(start <= end) {
            if(abs(num - arr2[mid]) <= d) {
                return false;
            }
            else if(num < arr2[mid]) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        //Brute Force, TC: O(n*m), SC: O(1)
        int i=0, j=0, count=0;
        while(i < arr1.size()) {
            if(j < arr2.size()) {
                int diff = abs(arr1[i] - arr2[j]);
                if(diff > d) j++;
                else {
                    i++; j=0;
                }
            }
            if(j == arr2.size()) {
                count++; i++; j=0;
            }
        }
        return count;

        //Approach:2 Binary Search
        //TC: O(*logn + logn) = O(n*logn), SC: O(n)
        sort(arr2.begin(), arr2.end());
        //we will fin the upper and lower bound of each arr[i]+d if both exist cnt++
        int cnt=0;
        for(int num : arr1) {
            if(isValidElement(arr2, num, d)) {
                cnt++;
            }
        }
        return cnt;
    }
};
