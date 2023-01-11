class Solution {
    unordered_map<int, vector<int>> um;
    vector<bool> visited;
public:
    int dfs(int node, int initialCost, vector<bool>& hasApple) {
        if (visited[node]) return 0;
        visited[node] = true;
        int currentCost = 0;
        for (int i = 0; i < um[node].size(); i++) {
            currentCost += dfs(um[node][i], 2, hasApple);
        }
        if (currentCost == 0 && hasApple[node] == false) return 0;
        return currentCost + initialCost;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        um.clear();
        for (auto& e: edges) {
            um[e[0]].push_back(e[1]);
            um[e[1]].push_back(e[0]);
        }
        visited.resize(n, false);
        return dfs(0, 0, hasApple);
    }
};
