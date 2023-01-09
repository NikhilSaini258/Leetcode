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
    vector<int> ans;
public:
    void preOrderRecursive(TreeNode* node) {
        if (node == nullptr) return;
        ans.push_back(node->val);
        preOrderRecursive(node->left);
        preOrderRecursive(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        ans.clear();
        preOrderRecursive(root);
        return ans;
    }
};
