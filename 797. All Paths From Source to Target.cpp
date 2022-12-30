class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int vertex) {
        path.push_back(vertex);

        if (vertex == graph.size() - 1) {
            paths.push_back(path);
        }
        for (auto& e : graph[vertex]) {
            dfs (graph, paths, path, e);
        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths, path, 0);
        return paths;
    }
};
