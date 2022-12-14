// Recursion Solution
class Solution {
public:
    int solve(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }
        int selected = nums[index] + solve(nums, index+2);
        int notSelected = solve(nums, index+1);
        return std::max(selected, notSelected);
    }
    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
};

// DP solution
class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return 0;
        } else if (dp[index] != -1) {
            return dp[index];
        }
        int selected = nums[index] + solve(nums, index+2);
        int notSelected = solve(nums, index+1);
        dp[index] = std::max(selected, notSelected);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};
