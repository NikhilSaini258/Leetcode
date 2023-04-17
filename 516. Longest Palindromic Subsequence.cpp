// Recursive approach
class Solution {
public:
    int solve (string& s1, string& s2, int i, int j) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if (s1[i-1] == s2[j-1]) {
            return 1 + solve (s1, s2, i-1, j-1);
        } else {
            return std::max (solve (s1, s2, i-1, j), solve (s1, s2, i, j-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        std::reverse (s2.begin(), s2.end());
        return solve (s, s2, s.size(), s2.size());
    }
};

// Memorization approach
class Solution {
public:
    int solve (string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) {
            dp[i][j] = 0;
            return dp[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i-1] == s2[j-1]) {
            dp[i][j] = 1 + solve(s1, s2, i-1, j-1, dp);
        } else {
            dp[i][j] = std::max (solve(s1, s2, i-1, j, dp), solve(s1, s2, i, j-1, dp));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp (s.size()+1, vector<int>(s.size()+1, -1));
        string s2 = s;
        std::reverse (s2.begin(), s2.end());
        return solve (s, s2, s.size(), s2.size(), dp);
    }
};

// Top Down Approach
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp (n+1, vector<int> (n+1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (s[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};
