class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       //TC: O(n*m), SC: O(1)
       int maxWealth = 0;
       for(int i=0; i<accounts.size(); i++) {
            int sum = 0;
            for(int j=0; j<accounts[0].size(); j++) {
                sum += accounts[i][j];
            }
            maxWealth = max(maxWealth, sum);
       } 
       return maxWealth;
    }
};
