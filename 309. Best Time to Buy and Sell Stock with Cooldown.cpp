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
                                0 + calculateProfit(prices, 0, index+2) );
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
public:
    int calculateProfit(vector<int>& prices, int buy, int index, vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }
        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }
        int profit = 0;
        if (buy) {          // Buy stock condition
            profit = std::max (-prices[index] + calculateProfit(prices, 0, index + 1, dp), 
                                0 + calculateProfit(prices, 1, index + 1, dp));
        } else {            // Sell stock condition
            profit = std::max (prices[index] + calculateProfit(prices, 1, index + 2, dp), 
                                0 + calculateProfit(prices, 0, index + 1, dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        vector<vector<int>> dp (prices.size(), vector<int>(2, -1));
        return calculateProfit(prices, 1, 0, dp);
    }
};

// DP with tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        int n = prices.size();
        vector<vector<int>> dp (n + 2, vector<int>(2, 0));  // Here (n+2) --> sells condition jumps by 2
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                if (buy == 1) {     // Buy stock condition
                    dp[i][buy] = std::max(-prices[i] + dp[i+1][0],
                                        0 + dp[i+1][1] );
                } else {            // Sell stock condition
                    dp[i][buy] = std::max(prices[i] + dp[i+2][1],
                                        0 + dp[i+1][0] );
                }
            }
        }
        return dp[0][1];
    }
};

// Since inner FOR loop is running for only 2 condition and each condition have different if-else block, we can ommit the inner for loop
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        int n = prices.size();
        vector<vector<int>> dp (n + 2, vector<int>(2, 0));  // Here (n+2) --> sells condition jumps by 2
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            // Buy stock condition
            dp[i][1] = std::max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1] );

            // Sell stock condition
            dp[i][0] = std::max(prices[i] + dp[i+2][1], 0 + dp[i+1][0] );
        }
        return dp[0][1];
    }
};
