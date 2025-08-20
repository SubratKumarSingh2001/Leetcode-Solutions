class Solution {
public:
    void merge(vector<int> &nums, int start, int end, int mid) {
        //take a temporary array to merge into two sorted array
        vector<int> temp;
        int i = start, j=mid+1;

        //now we wil store the array in temporary array
        while(i<=mid && j<=end) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        //if elements on left half still present
        while(i<=mid) {
            temp.push_back(nums[i]);
            i++;
        }
        //if elements on right half still present
        while(j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        //now store in the actual array
        for(int i=start; i<=end; i++) {
            nums[i] = temp[i-start]; //because the start wont be same i.e 0 in each half 
        }
    }

    int countPairs(vector<int> & nums, int start, int mid, int end) {
        int cnt=0, j=mid+1;
        for(int i=start; i<=mid; i++) {
            while(j<=end && (long long)nums[i] > 2*(long long)nums[j]) {
                j++;
            }
            cnt += j - (mid+1);
        }
        return cnt;
    }
    int mergeSort(vector<int> &nums, int start, int end) {
        int cnt = 0;
        //if we have single element and start and end crosses each other return the cnt
        if(start >= end) return cnt;
        int mid = (start + end)/2;
        /*now when we are dividing the array into two halves the left part of the array might
        be giving some cnt of the reverse pairs that we will add on*/
        cnt += mergeSort(nums, start, mid);
        //same we have to do for right part of the array
        cnt += mergeSort(nums, mid+1, end);
        /*now before merging them into single sorted array we have left and right part of the
        array for which wer have count the no.of reverse pairs and then merge into the single
        sorted array*/
        //this will also return some cnt value of each merge 
        cnt += countPairs(nums, start, mid, end);
        //now after all the cnt value have been updated we will merge the array
        merge(nums, start, end, mid);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        //Brute Force, TC: O(n^2), SC: O(1)
        // int cnt = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     for(int j=i+1; j<nums.size(); j++) {
        //         if(nums[i] > 2*nums[j]) cnt++;
        //     }
        // }
        // return cnt;

        //Optimal Soluiton: Using Divide and Conqueror, Merge Sort
        //TC: O(nlogn + nlogn = 2*nlogn), SC: O(N)
        int cnt = mergeSort(nums, 0, nums.size()-1);
        return cnt;
    }
};
