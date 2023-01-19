// Basic solution using auxillary array for storing cumulative sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        vector<int> prefixSum = nums;
        for (int i = 1; i < nums.size(); i++) prefixSum[i] += prefixSum[i-1];

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (i == 0) sum = prefixSum[j];
                else sum = prefixSum[j] - prefixSum[i-1];
                if (sum == k) ans++;
            }
        }

        return ans;
    }
};

// Basic solution - Space Optimized
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) ans++;
            }
        }

        return ans;
    }
};

// Prefix solution - Best
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0;
        int sum = 0;
        unordered_map<int, int> um; // {sum, count}

        while (i < nums.size()) {
            sum += nums[i];
            if (sum == k) ans++;
            if (um.find(sum-k) != um.end()) ans += um[sum-k];
            um[sum]++;
            i++;
        }

        return ans;
    }
};
