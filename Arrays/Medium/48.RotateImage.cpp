class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //here we can see that matrix is rotated 90deg clockwise 
        //first find the tranpose of the matrix 
        //This is in-place TC: O(n^2), SC: O(1)
        for(int i=0; i<matrix.size(); i++) {
            for(int j=i; j<matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //now for clockwise 90deg we will reverse each row
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<(matrix[0].size())/2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size()-j-1];
                matrix[i][matrix.size()-j-1] = temp;
            }
        }
    }
};
