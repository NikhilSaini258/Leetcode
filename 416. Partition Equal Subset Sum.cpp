class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int requiredSum = sum / 2;
        vector<vector<bool>> dp (n+1, vector<bool> (requiredSum + 1, false));

        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int j = 1; j <= requiredSum; j++) dp[0][j] = false;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= requiredSum; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][requiredSum] ? true : false;
    }
};
