class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); //no. of rows
        int n = matrix[0].size(); //no. of cols
        int totalCount = m*n;
        
        vector<int> ans;
        int startRow = 0;
        int endCol = n-1;
        int endRow = m-1;
        int startCol = 0;
        
        int count=0;
        //here we have to run the loop till all the elements of matrix are printed
        while(count < totalCount) {
            //first print the first row 
            for(int i=startRow; i<=endCol && count< totalCount; i++) {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            //second print the last column
            for(int i=startRow; i<=endRow && count< totalCount; i++) {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            //third print the last row
            for(int i=endCol; i>=startCol && count< totalCount; i--) {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            //fourth print the first column
            for(int i=endRow; i>=startRow && count< totalCount; i--) {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};
