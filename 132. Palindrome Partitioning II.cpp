// Recursive Solution
class Solution {
public:
    bool isPalindrome(string& s, int startIndex, int endIndex) {
        while (startIndex < endIndex) {
            if(s[startIndex] != s[endIndex]) {
                return false;
            }
            startIndex++;
            endIndex--;
        }
        return true;
    }
    int solve (string& s, int i, int j) {
        if (i >= j || isPalindrome(s, i, j)) {
            return 0;
        }
        int ans = INT_MAX;
        int temp;
        for (int k = i; k <= j-1; k++) {
            temp = 1 + solve(s, i, k) + solve(s, k+1, j);
            ans = min(ans, temp);
        }
        return ans;
    }
    int minCut(string s) {
        return solve(s, 0, s.size()-1);
    }
};

// Recursive with memorization
class Solution {
public:
    int dp[2002][2002];
    bool isPalindrome(string& s, int startIndex, int endIndex) {
        while (startIndex < endIndex) {
            if(s[startIndex] != s[endIndex]) {
                return false;
            }
            startIndex++;
            endIndex--;
        }
        return true;
    }
    int solve (string& s, int i, int j) {
        if (i >= j || isPalindrome(s, i, j)) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        int temp;
        for (int k = i; k <= j-1; k++) {
            temp = 1 + solve(s, i, k) + solve(s, k+1, j);
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size()-1);
    }
};

// Optimized recursive with memorization
class Solution {
public:
    int dp[2002][2002];
    bool isPalindrome(string& s, int startIndex, int endIndex) {
        while (startIndex < endIndex) {
            if(s[startIndex] != s[endIndex]) {
                return false;
            }
            startIndex++;
            endIndex--;
        }
        return true;
    }
    int solve (string& s, int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (isPalindrome(s, i, j)) return 0;
        int ans = INT_MAX;
        int temp;
        for (int k = i; k <= j-1; k++) {
            // Only check palindrome for range i to k, since remaining partition can be further split into more partition
            if (isPalindrome(s, i, k)) {
                // Checking range from i to k
                if (dp[i][k] == -1) dp[i][k] = solve(s, i, k);

                // Checking range from k+1 to j
                if (dp[k+1][j] == -1) dp[k+1][j] = solve(s, k+1, j);

                temp = 1 + dp[i][k] + dp[k+1][j];
                ans = min(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size()-1);
    }
};
