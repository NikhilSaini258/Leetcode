class Solution {
public:
    void dfs (vector<vector<int>>& conn, vector<bool>& visited, int index) {
        visited[index] = true;
        for (auto& e: conn[index]) {
            if (!visited[e]) {
                // Visit all connected nodes -> like we do in question of count Island
                // The nodes that are connected, form a single Island
                dfs (conn, visited, e);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) {
            return -1;
        }
        // Now we are sure that we can connect the whole graph
        vector<vector<int>> conn(n);    // Connection adjacency matrix
        for (auto& e: connections) {
            conn[e[0]].push_back(e[1]);
            conn[e[1]].push_back(e[0]);
        }
        int count = 0;
        vector<bool> visited (n, false);    // Record visited nodes 
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                // We only need to count the number of connected networks.
                // Now it becomes the question of Counting number of Islands 
                dfs (conn, visited, i);
                count++;
            }
        }
        // The number of operations we need = (the number of connected networks - 1)
        return count-1;
    }
};
