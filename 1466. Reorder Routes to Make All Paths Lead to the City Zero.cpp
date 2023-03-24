class Solution {
public:
    int dfs(vector<vector<int>>& conn, vector<bool>& visited, int from) {
        int count = 0;
        visited[from] = true;
        for (auto& to: conn[from]) {
            if (!visited[std::abs(to)]) {
                count += dfs(conn, visited, std::abs(to)) + (to > 0 ? 1 : 0);
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // Based on the problem description, we have a tree, and node zero is the root.
        vector<vector<int>> conn (n);
        for (auto& e: connections) {
            conn[e[0]].push_back(e[1]);     // Parent to child. We need to reverse this
            conn[e[1]].push_back(-e[0]);    // Child to parent, Used negative sign to denote oppsoite direction
        }
        vector<bool> visited (n, false);
        return dfs (conn, visited, 0);
    }
};
