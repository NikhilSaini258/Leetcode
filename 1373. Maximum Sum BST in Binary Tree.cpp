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

class NodeValue {
public:
    int minValue, maxValue, sumOfBst;
    NodeValue(int min, int max, int sum) {
        minValue = min;
        maxValue = max;
        sumOfBst = sum;
    }
};

class Solution {
    NodeValue maxSumBSTHelper(TreeNode* root, int& sumOfBst) {
        if (root == nullptr) {
            return NodeValue (INT_MAX, INT_MIN, 0);
        }
        auto left = maxSumBSTHelper (root->left, sumOfBst);
        auto right = maxSumBSTHelper (root->right, sumOfBst);

        if (left.maxValue < root->val && root->val < right.minValue) {
            // Valid BST
            sumOfBst = std::max (sumOfBst, root->val + left.sumOfBst + right.sumOfBst);
            return NodeValue (std::min (left.minValue, root->val), 
                            std::max (right.maxValue, root->val), 
                            root->val + left.sumOfBst + right.sumOfBst);
        }
        sumOfBst = std::max (sumOfBst, std::max (left.sumOfBst, right.sumOfBst));
        return NodeValue (INT_MIN, INT_MAX, std::max (left.sumOfBst, right.sumOfBst));
    }
public:
    int maxSumBST(TreeNode* root) {
        int sumOfBst = 0;
        maxSumBSTHelper (root, sumOfBst);
        return sumOfBst;
    }
};
