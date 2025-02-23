class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //TC: O(logn), SC: O(1)
        int m = matrix.size(); //no.of rows
        int n = matrix[0].size(); // no.of cols
        int start = 0, end = m*n - 1;
        int mid = start + (end-start)/2;
        while(start <= end) {
            //we have to calculate the row and col index to access the element 
            int rowIndex = mid/n; 
            int colIndex = mid%n;
            if(matrix[rowIndex][colIndex] == target) {
                return true;
            }
            else if(matrix[rowIndex][colIndex] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }
        return false;
    }
};
