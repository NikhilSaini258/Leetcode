class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans (queries.size());
        vector<int> prefixSum (nums.size());
        std::sort(nums.begin(), nums.end());
        prefixSum[0] = nums[0];
        for (int i = 1; i < prefixSum.size(); i++) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = upper_bound(prefixSum.begin(), prefixSum.end(), queries[i]) - prefixSum.begin();
        }
        return ans;
    }
};
