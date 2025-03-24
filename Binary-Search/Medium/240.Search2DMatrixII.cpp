class Solution {
public:
    bool search(vector<int> &row, int target) {
        int start=0, end=row.size()-1;
        int mid = start + (end-start)/2;
        while(start <= end) {
            if(row[mid] == target) return true;
            else if(row[mid] > target) end = mid-1;
            else start = mid+1;
            mid = start + (end-start)/2;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Brute Force using two nested loops and find target element
        //TC: O(n^2), SC: O(1);

        /*Better Approach: As each row is sorted in asc order, therefore we will hold
        every row and treat it as 1D Array and find the target if found return true
        else move to another row and again search in 1D Array 
        TC: O(N*logm), SC: O(1), where n=no.of rows, m=no.of cols
        */
        for(int i=0; i<matrix.size(); i++) {
            if(search(matrix[i], target)) return true;
        }
        return false;

        //Optimal Solution, TC: O(m+n), SC: O(1);
        //Going like walking is stairs and checking whether, the position we stand is target if not, the the target all are greater move left if vice-versa move down
        int row=0, col=matrix[0].size()-1;
        while(row < matrix.size() && col >= 0) {
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][col] < target) {
                row++;
            }
            else {
                col--;
            }
        }
        return false;       
    }
};
