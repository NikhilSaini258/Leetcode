// DP with tabulation with space optimized
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // buy --> 0 --> Sell
        // buy --> 1 --> Buy
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));

        // Bases cases of DP is handled since we set the values of dp to 0
        for (int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap < k+1; cap++) {
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
        return ahead[1][k];
    }
};

// Refer previous solved problems on Buy/Sell stock to understand above solution better
