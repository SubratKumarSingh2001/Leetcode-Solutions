class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //TC: O(n*m), SC: O(1)
        int row = grid.size(), col = grid[0].size();
        int perimeter = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                //first check whether the cell has value 1 if yes then proceed else not
                if(grid[i][j] == 1) {
                    //top cell check if it is 0 or the first row
                    if(i==0 || grid[i-1][j] == 0) perimeter++;
                    //bottom cell check if it is 0 or the last row
                    if(i==row-1 || grid[i+1][j] == 0) perimeter++;
                    //left cell check if it is 0 or the first column
                    if(j == 0 || grid[i][j-1] == 0) perimeter++;
                    //right cell check if it is 0 or the last column
                    if(j == col-1 || grid[i][j+1] == 0) perimeter++;
                }
            }
        }
        return perimeter;
    }
};
