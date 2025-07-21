class Solution {
public:
    long long findnCr(int n, int r) {
        long long res = 1;
        for(int i=0; i<r; i++) {
            res = res * (n-i)/(i+1);
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        //TC: O(rowIndex*r), SC: O(rowIndex) 
        vector<int> ans;
        //Brute Force 
        for(int i=0; i<=rowIndex; i++) {
            long long ele = findnCr(rowIndex, i);
            ans.push_back(ele);
        }
        return ans;

        //Optimal Solution: O(n=rowIndex), SC: O(rowIndex)
        vector<int> ans;
        long long res = 1;
        ans.push_back(res);
        for(int i=1; i<=rowIndex; i++) {
            res =  res * (rowIndex - i + 1)/ i;
            ans.push_back(res);
        }
        return ans;
    }
};
