class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int runningSum = 0;
        int startIndex, endIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (runningSum == 0) {
              startIndex = i;
            }
            runningSum += nums[i];
            if (runningSum > maxSum) {
                maxSum = runningSum;
                endIndex = i;
            }
            if (runningSum < 0) {
                runningSum = 0;
            }
        }
        for (int i = startIndex; i <= endIndex; i++) {
            // Printing max Sub-Array
            cout << nums[i] << " ";
        }
        return maxSum;
    }
};
