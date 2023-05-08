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
    bool check (TreeNode* root, long minRange, long maxRange) {
        if (root == nullptr) {
            return true;
        }
        return (root->val < maxRange && root->val > minRange) && 
            check (root->left, minRange, root->val) &&
            check (root->right, root->val, maxRange);
    }
    bool isValidBST(TreeNode* root) {
        return check (root, LONG_MIN, LONG_MAX);
    }
};
