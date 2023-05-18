class Solution {
public:
    void generateAndCalculate (vector<int>& candidates, vector<int>& subset, vector<vector<int>>& allSubset, int target, int index) {
        if (index == candidates.size()) {
            if (target == 0) {
                allSubset.push_back (subset);
            }
            return;
        }

        // Current index is not selected
        generateAndCalculate (candidates, subset, allSubset, target, index+1);

        if (candidates[index] <= target) {
            // Select current index, only if current index value is less than or equal to required target
            int remainingTarget = target - candidates[index];
            subset.push_back (candidates[index]);
            generateAndCalculate (candidates, subset, allSubset, remainingTarget, index);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allSubset;
        vector<int> subset;

        generateAndCalculate (candidates, subset, allSubset, target, 0);
        return allSubset;
    }
};
