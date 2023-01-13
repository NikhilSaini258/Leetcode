class Solution {
    unordered_map<int, vector<int>> um;
    int dfs(string& s, int index, int& ans) {
        int big1 = 0;   // We need to make it bigger and return it
        int big2 = 0;
        for (auto& e: um[index]) {
            int curr = dfs(s, e, ans);
            if (s[index] == s[e]) continue;
            if (curr > big2) big2 = curr;
            if (big2 > big1) std::swap(big1, big2);
        }
        ans = max(ans, 1+big1+big2);
        return 1+big1;
    }
public:
    int longestPath(vector<int>& parent, string& s) {
        um.clear();
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            um[parent[i]].push_back(i);
        }
        dfs (s, 0, ans);
        return ans;
    }
};
