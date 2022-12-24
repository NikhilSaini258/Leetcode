// Recursion
class Solution {
public:
    int calculateProfit(vector<int>& prices, int buy, int index, int cap) {
        if (index >= prices.size() || cap == 0) {
            return 0;
        }
        int profit = 0;
        if (buy == 1) {  // Buy stock condition
            profit = max(-prices[index] + calculateProfit(prices, 0, index+1, cap),
                            0 + calculateProfit(prices, 1, index+1, cap) );
        } else {  // Sell stock condition
            profit = max(prices[index] + calculateProfit(prices, 1, index+1, cap-1),
                            0 + calculateProfit(prices, 0, index+1, cap) );
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        return calculateProfit(prices, 1, 0, 2);
    }
};

// Recursion with Memorization
class Solution {
public:
    int calculateProfit(vector<int>& prices, int buy, int index, int cap, vector<vector<vector<int>>>& dp) {
        if (index == prices.size() || cap == 0) {
            return 0;
        }
        if (dp[index][buy][cap] != -1) {
            return dp[index][buy][cap];
        }
        int profit = 0;
        if (buy == 1) {  // Buy stock condition
            profit = max(-prices[index] + calculateProfit(prices, 0, index+1, cap, dp),
                            0 + calculateProfit(prices, 1, index+1, cap, dp) );
        } else {  // Sell stock condition
            profit = max(prices[index] + calculateProfit(prices, 1, index+1, cap-1, dp),
                            0 + calculateProfit(prices, 0, index+1, cap, dp) );
        }
        return dp[index][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        vector<vector<vector<int>>> dp (prices.size(), 
                                        vector<vector<int>>(2, vector<int>(3, -1)));
        return calculateProfit(prices, 1, 0, 2, dp);
    }
};

// DP with tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        int n = prices.size();
        vector<vector<vector<int>>> dp (n + 1, 
                                        vector<vector<int>>(2, vector<int>(3, 0)));

        // Bases cases of DP is handled since we set the values of dp to 0
        for (int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap < 3; cap++) {
                    if (buy == 1) {  // Buy stock condition
                        dp[index][buy][cap] = max(-prices[index] + dp[index+1][0][cap],
                                        0 + dp[index+1][1][cap] );
                    } else {  // Sell stock condition
                        dp[index][buy][cap] = max(prices[index] + dp[index+1][1][cap-1],
                                        0 + dp[index+1][0][cap] );
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};

// DP with tabulation with space optimized
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        // Bases cases of DP is handled since we set the values of dp to 0
        for (int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap < 3; cap++) {
                    if (buy == 1) {  // Buy stock condition
                        curr[buy][cap] = max(-prices[index] + ahead[0][cap],
                                        0 + ahead[1][cap] );
                    } else {  // Sell stock condition
                        curr[buy][cap] = max(prices[index] + ahead[1][cap-1],
                                        0 + ahead[0][cap] );
                    }
                    ahead = curr;
                }
            }
        }
        return ahead[1][2];
    }
};
