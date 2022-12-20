// BFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::unordered_map<int, vector<int>> umap;
        for (int i = 0; i < rooms.size(); i++) {
            for (auto& each : rooms[i]) {
                umap[i].push_back(each);
            }
        }
        std::queue<int> q;
        q.push(0);
        vector<bool> unlock (rooms.size(), false);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            unlock[curr] = true;
            for (auto& e : rooms[curr]) {
                if (unlock[e] == false) {
                    q.push(e);
                }
            }
        }

        for(auto e : unlock) {
            if (e == false) {
                return false;
            }
        }
        return true;
    }
};

// DFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> unlock (rooms.size(), false);

        dfs (rooms, unlock, 0);

        for(auto e : unlock) {
            if (e == false) return false;
        }
        return true;
    }

    void dfs(vector<vector<int>>& rooms, vector<bool>& unlock, int i) {
        if (unlock[i] == true) {
            return;
        }
        unlock[i] = true;
        for (int j = 0; j < rooms[i].size(); j++) {
            dfs (rooms, unlock, rooms[i][j]);
        }
    }
};
