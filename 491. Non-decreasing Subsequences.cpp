class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& nums, int index, vector<int>& temp) {
        if (temp.size() > 1) ans.push_back(temp);
        unordered_set<int> hash;

        for (int i = index; i < nums.size(); i++) {
            if ((temp.empty() || nums[i] >= temp.back()) && hash.find(nums[i]) == hash.end()) {
                temp.push_back(nums[i]);
                solve(nums, i+1, temp);
                temp.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        vector<int> temp;
        solve(nums, 0, temp);
        return ans;
    }
};
