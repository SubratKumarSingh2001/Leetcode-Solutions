class Solution {
public:
    long long findnCr(int n, int r) {
        long long res = 1;
        for(int i=0; i<r; i++) {
            res = res * (n-i)/(i+1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        //Brute Force : Same as Pascal's Triangle-II
        //TC: O(n*n*r) approax to O(n^3)
        vector<vector<int>> ans; 
        ans.push_back({1});
        for(int i=1; i<numRows; i++) {
            vector<int> res;
            for(int j=0; j<i+1; j++) {
                long long ele = findnCr(i, j);
                res.push_back(ele);
            }
            ans.push_back(res);
        }   
        return ans;

        //Optimal Solution 
        //TC: O(n^2)
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1; i<numRows; i++) {
            vector<int> res;
            res.push_back(1);
            int temp = 1;
            for(int j=1; j<i+1; j++) {
                temp =  temp * (i-j+1)/j;
                res.push_back(temp);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
