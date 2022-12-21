// BFS
class Solution {
public:
    unordered_map<int, vector<int>> umap;
    bool checkBipartition(int n, vector<vector<int>>& dislikes, vector<int>& color) {
        queue<int> q;
        q.push(n);
        color[n] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& e : umap[curr]) {
                if (color[e] == color[curr]) {
                    return false;
                } else if (color[e] == -1) {
                    q.push(e);
                    color[e] = 1 - color[curr];
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for (auto& e : dislikes) {
            umap[e[0]].push_back(e[1]);
            umap[e[1]].push_back(e[0]);
        }
        vector<int> color (n+1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!checkBipartition(i, dislikes, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};

// Solution is explained here
// https://www.youtube.com/watch?v=0ACfAqs8mm0
