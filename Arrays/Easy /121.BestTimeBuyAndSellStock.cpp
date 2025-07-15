class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Brute Force : Nested Loop
        //TC: O(n^2), SC: O(1)
        int maxProfit = 0;
        for(int i=0; i<prices.size()-1; i++) {
            for(int j=i+1; j<prices.size(); j++) {
                if(prices[i] < prices[j]) {
                    int profit = prices[j] - prices[i];
                    maxProfit = max(maxProfit, profit);
                }
            }
        }
        return maxProfit;

        //Optimal Solution: Dynamic Programming (Remembering the past)
        //TC: O(n), SC: O(1)
        int maxProfit=0, mini = prices[0];
        for(int i=1; i<prices.size(); i++) {
            //the cost calculate means when we coud have buyed the stock for max profit
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            //we have to update the mini also from the mini befoe and curr prices
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};
