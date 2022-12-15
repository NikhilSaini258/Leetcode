// Recursive Solution
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0 , 0);
    }
    int solve(string text1, string text2, int index1, int index2) {
        if (index1 >= text1.size() || index2 >= text2.size()) {
            return 0;
        }
        if (text1[index1] == text2[index2]) {
            return 1 + solve(text1, text2, index1 + 1, index2 + 1);
        }
        return std::max(solve(text1, text2, index1 + 1, index2), solve(text1, text2, index1, index2 + 1));
    }
};

// DP Solution
class Solution {
public:
    int dp[1002][1002];
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(text1, text2, 0 , 0);
    }
    int solve(string& text1, string& text2, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1);
            return dp[i][j];
        }
        dp[i][j] = std::max(solve(text1, text2, i + 1, j), solve(text1, text2, i, j + 1));
        return dp[i][j];
    }
};
