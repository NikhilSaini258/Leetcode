// DP solution
class Solution {
public:
    bool solve(vector<int>& nums, int index, vector<int>& dp) {
        if (index == nums.size() - 1) {
            return 1;
        } else if (index >= nums.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        for (int j = nums[index]; j > 0; j--) {
            dp[index] = solve(nums, index + j, dp);
            if (dp[index] == 1) {
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp (nums.size()+1, -1);
        return solve(nums, 0, dp);
    }
};

// Smart Solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int lastPos = n;

        for (int i = n-1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};
