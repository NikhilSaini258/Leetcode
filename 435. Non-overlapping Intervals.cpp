class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        if (intervals.size() < 2) return ans;
        std::sort(intervals.begin(), intervals.end(), Solution::comp);

        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                ans++;
            } else {
                end = intervals[i][1];
            }
        }

        return ans;
    }
};
