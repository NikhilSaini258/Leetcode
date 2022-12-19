class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        std::unordered_map<int, vector<int>> umap;
        for (auto& e : edges) {
            umap[e[0]].push_back(e[1]);
            umap[e[1]].push_back(e[0]);
        }

        std::vector<bool> visitedNodes (n, false);
        std::queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (start == destination) {
                return true;
            }
            for (auto& e : umap[start]) {
                if (!visitedNodes[e]) {
                    visitedNodes[e] = true;
                    q.push(e);
                }
            }
        }
        return false;
    }
};
