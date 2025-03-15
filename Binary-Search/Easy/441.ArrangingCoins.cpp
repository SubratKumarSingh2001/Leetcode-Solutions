class Solution {
public:
    int arrangeCoins(int n) {
        /*
        Brute Force
        TC: O(sqrt(n)), Because the k=1,2,3....k max value is sum k(k+1)/2 <=n, so 
        the aproximate TC will be sqrt(n)
        SC: O(1)
        */
        int k=1;
        while(n >= k) {
            n = n - k;
            k++;
        }
        return --k;

        //Approach:2 Binary Search
        //TC: O(logn), SC: O(1)
        int start=1, end=n; 
        //we will type long long row to avoid implicit cnversion
        long long row = start + (end-start)/2;
        while(start <= end) {
            //Calculate the total number of coins can accomdate till the ith row
            long long totalCoins = (row*(row+1))/2;
            if(totalCoins == n) {
                return row;
            }
            else if(totalCoins > n) {
                end = row-1;
            }
            else {
                start = row+1;
            }
            row = start + (end-start)/2;
        }
        return end;
    }
};
