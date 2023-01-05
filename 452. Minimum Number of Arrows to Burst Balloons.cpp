class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        int arrowsCount = 1;
        std::sort(points.begin(), points.end(), Solution::comp);

        int end = points[0][1];
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] > end) {
                arrowsCount++;
                end = points[i][1];
            }
        }

        return arrowsCount;
    }
};
