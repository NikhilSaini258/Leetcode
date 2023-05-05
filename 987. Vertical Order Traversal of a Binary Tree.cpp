/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        std::map<int, map<int, multiset<int>>> m;   // {x-Index, y-Index, TreeNode values at that index}
        std::queue<pair<TreeNode*, pair<int, int>>> q; // {TreeNode*, x-Index, y-Index}
        q.push ({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            m[x][y].insert (node->val);

            if (node->left) q.push ({node->left, { x-1, y+1 }});
            if (node->right) q.push ({node->right, { x+1, y+1 }});
        }

        for (auto& it: m) {
            vector<int> v;
            for (auto& e: it.second) {
                v.insert (v.end(), e.second.begin(), e.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};
