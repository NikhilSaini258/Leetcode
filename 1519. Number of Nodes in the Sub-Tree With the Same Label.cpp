// Using Adjacency List for Graph
class Solution {
    unordered_map<int, vector<int>> um;
    unordered_set<int> visited;
    vector<int> ans;
  
    vector<int> dfs(int index, string& labels) {
        vector<int> counts (26, 0);
        visited.insert(index);
        for (int i = 0; i < um[index].size(); i++) {
            if (visited.find(um[index][i]) != visited.end()) continue;
            vector<int> tempCount = dfs(um[index][i], labels);
            for (int i = 0; i < 26; i++) counts[i] += tempCount[i];
        }
        counts[labels[index] - 'a']++;
        ans[index] = counts[labels[index] - 'a'];
        return counts;
    }
  public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string& labels) {
        um.clear();
        ans.resize(n, 0);
        for (auto& e : edges) {
            um[e[0]].push_back(e[1]);
            um[e[1]].push_back(e[0]);
        }
        dfs(0, labels);
        return ans;
    }
};
