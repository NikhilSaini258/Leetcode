class Solution {
public:
    // Input might contain duplicate data
    void generateAndCalculate (vector<int>& candidates, vector<int>& subset, vector<vector<int>>& allSubset, int target, int index) {
        if (target == 0) {
            allSubset.push_back (subset);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) {
                // This will avoid duplicate
                continue;
            } else if (target < candidates[i]) {
                // There is no point to search further as array is already sorted
                // So, all remaining values will be greater than given target
                break;
            }
            int remainingTarget = target - candidates[i];
            subset.push_back (candidates[i]);
            generateAndCalculate (candidates, subset, allSubset, remainingTarget, i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> allSubset;
        vector<int> subset;

        std::sort (candidates.begin(), candidates.end());
        generateAndCalculate (candidates, subset, allSubset, target, 0);
        return allSubset;
    }
};
