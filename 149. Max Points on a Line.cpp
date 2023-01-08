class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for (int i = 0; i < points.size()-1; i++) {
            unordered_map<double, int> um;  // {slope, countOfThatSlope}
            for (int j = i+1; j < points.size(); j++) {
                if (points[i][0] == points[j][0]) um[INT_MAX]++;
                else {
                    double slope = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
                    um[slope]++;
                }
            }
            int maxCount = 0;
            for (auto& e : um) {
                maxCount = max(maxCount, e.second);
            }
            ans = max(ans, maxCount+1);
        }
        return ans;
    }
};
