class Solution {
public:
    vector<int> twoPointerApp(vector<int> &arr, int k, int x) {
        int start=0, end=arr.size()-1;
        while(end-start >= k) {
            if(abs(x-arr[start]) > abs(x-arr[end])) {
                start++;
            }
            else {
                end--;
            }
        }
        // vector<int> ans;
        // for(int i=start; i<=end; i++) {
        //     ans.push_back(arr[i]);
        // }
        return vector<int> (arr.begin()+start, arr.begin()+end+1);
    }

    int lowerBound(vector<int> &arr, int x) {
        int start=0, end=arr.size()-1;
        int mid = start + (end-start)/2;
        int ans=end;
        while(start <= end) {
            if(arr[mid] >= x) {
                ans = mid;
                end = mid-1;
            }
            else if(arr[mid] < x) {
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }

    vector<int> search(vector<int> &arr, int k, int x) {
        int high = lowerBound(arr, x);
        int low = high-1;
        while(k--) {
            if(low < 0) high++;
            else if(high >= arr.size()) low--;

            else if(arr[high]-x < x-arr[low]) {
                high++;
            }
            else {
                low--;
            }
        }

        return vector<int> (arr.begin()+low+1, arr.begin()+high);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //TC: O(n-k) equivalent to O(n-k), SC: O(k);
        return twoPointerApp(arr, k, x);   

        //Binary Search, TC: o(logn+k), SC: O(k);
        return search(arr, k, x);
    }
};
