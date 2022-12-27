class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> deficit (rocks.size());
        for (int i = 0; i < rocks.size(); i++) {
            deficit[i] = capacity[i] - rocks[i];
        }
        sort (deficit.begin(), deficit.end());
        int count = 0;
        for (auto& e : deficit) {
            if (e >= 0 && additionalRocks >= e) {
                count++;
                additionalRocks -= e;
            }
        }
        return count;
    }
};
