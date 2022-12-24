// https://www.interviewbit.com/problems/subset-sum-problem/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<bool>> dp (n+1, vector<bool>(B+1, false));
    
    for (int j = 1; j <= B; j++) {
        dp[0][j] = false;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= B; j++) {
            if (A[i-1] <= j) {
                dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][B] ? 1 : 0;
}
