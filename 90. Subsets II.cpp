class Solution {
public:
    void generate (vector<int>& nums, vector<int>& subset, vector<vector<int>>& allSubset, int index) {
        allSubset.push_back (subset);
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i-1]) {
                continue;
            }
            subset.push_back (nums[i]);
            generate (nums, subset, allSubset, i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubset;
        vector<int> subset;

        sort (nums.begin(), nums.end());
        generate (nums, subset, allSubset, 0);

        return allSubset;
    }
};
