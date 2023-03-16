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
    int sum;
    void calculate(TreeNode* root, int runningSum) {
        if (root == nullptr) {
            return;
        }
        runningSum = runningSum*10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += runningSum;
            return;
        }
        calculate(root->left, runningSum);
        calculate(root->right, runningSum);
    }
  public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        calculate(root, 0);
        return sum;
    }
};
