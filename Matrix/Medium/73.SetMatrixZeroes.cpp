class Solution {
public:
    void makeRow(vector<vector<int>> &matrix, int i) {
        //for all row -1 my column will only change 
        for(int j=0; j<matrix[0].size(); j++) {
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }
    void makeCol(vector<vector<int>> &matrix, int j) {
        //for all col -1 my row will only change 
        for(int i=0; i<matrix.size(); i++) {
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        //Brute Force, TC: O(n*m) +O(n+m) + O(n*m) = O(n^3) approx, SC: O(1)
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                //make that row and col all -1
                if(matrix[i][j] == 0) {
                   makeRow(matrix, i); makeCol(matrix, j); 
                }
            }
        }
        //now we have to mark all the -1 as 0 for the resultant ans
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == -1) matrix[i][j] = 0;
            }
        }

        /*Better Solution, earlier when 0 found we where marking entire row and col
        0 at the same time which results into tc of O(n^3) and now instead of 
        making whole row or col as 0 we will mark that row or col will have all 0*/
        //TC: O(n*m), SC: O(m+n)
        vector<int> row(matrix.size(), 0);
        vector<int> col(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1; col[j] = 1;
                }
            }
        }
        //now we will check if either of row[i] or col[j] has value 1 mark that cell 0
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        //Optimal Solution: Important to avoid the space used in better solution 
        //Understand this problem properly
        //TC: O(n*m), SC: O(1)

        //we will consider the first row and first column as our extra array as prvs ques
        int col0 = 1;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j==0) col0 = 0;
                    else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        //we will first ignore the first and last colu so as to remove any kind of prblms
        for(int i=1; i<matrix.size(); i++) {
            for(int j=1; j<matrix[0].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        //now we will check for the first row and first column
        //if first row first element is 0
        if(matrix[0][0] == 0) {
            for(int j=0; j<matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        //for first column we will be checking for col0
        if(col0 == 0) {
            for(int i=0; i<matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
