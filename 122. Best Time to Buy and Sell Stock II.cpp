// Recursion
class Solution {
  public:
    int calculateProfit(vector<int>& prices, int buy, int index) {
        if (index == prices.size()) {
            return 0;
        }
        int profit = 0;
        if (buy == 1) {
            profit = std::max(-prices[index] + calculateProfit(prices, 0, index+1),
                                0 + calculateProfit(prices, 1, index+1) );
        } else {
            profit = std::max(prices[index] + calculateProfit(prices, 1, index+1),
                                0 + calculateProfit(prices, 0, index+1) );
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        return calculateProfit(prices, 1, 0);
    }
};

// Recursion with Memorization
class Solution {
    int calculateProfit(vector<int>& prices, int buy, int index, vector<vector<int>>& dp) {
        if (index == prices.size()) {
            return 0;
        }
        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }
        int profit = 0;
        if (buy == 1) {     // Buy stock condition
            profit = std::max(-prices[index] + calculateProfit(prices, 0, index+1, dp),
                                0 + calculateProfit(prices, 1, index+1, dp) );
        } else {            // Sell stock condition
            profit = std::max(prices[index] + calculateProfit(prices, 1, index+1, dp),
                                0 + calculateProfit(prices, 0, index+1, dp) );
        }
        dp[index][buy] = profit;
        return dp[index][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        vector<vector<int>> dp (prices.size(), vector<int>(2, -1));
        return calculateProfit(prices, 1, 0, dp);
    }
};

// Cheat solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i-1] < prices[i]) {
                profit += prices[i] - prices[i-1];
            }
        }

        return profit;
    }
};
