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

// Interger Overflow can occur in below solution as, at each level, index increases in multiple of 2
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        if (root == nullptr) {
            return maxWidth;
        }
        std::queue<pair<TreeNode*, int>> q;   // queue <{TreeNode*, indexOfNode}>
        q.push ({root, 0});

        while (!q.empty()) {
            int size = q.size();
            int leftMostIndex, rightMostIndex;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if (i == 0) leftMostIndex = node.second;
                if (i == size-1) rightMostIndex = node.second;
                if (node.first->left) q.push ({node.first->left, (2*node.second) + 1});
                if (node.first->right) q.push ({node.first->right, (2*node.second) + 2});
            }
            maxWidth = std::max(maxWidth, (rightMostIndex - leftMostIndex + 1));
        }

        return maxWidth;
    }
};

// To avoid integer overflow, we reset index at the start of, level order traversal.
// So, at each level, index starts from 1
// In previous solution, index starts at (2 x parentIndex + 1)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        if (root == nullptr) {
            return maxWidth;
        }
        std::queue<pair<TreeNode*, int>> q;   // queue <{TreeNode*, indexOfNode}>
        q.push ({root, 0});

        while (!q.empty()) {
            int size = q.size();
            int minIndex = q.front().second;
            int leftMostIndex, rightMostIndex;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                int currIndex = node.second-minIndex;
                if (i == 0) leftMostIndex = node.second;
                if (i == size-1) rightMostIndex = node.second;
              
                // (long long) in below calculation is to avoid integer multiplication, which can overflow.
                if (node.first->left) q.push ({node.first->left, (long long)2*currIndex + 1});
                if (node.first->right) q.push ({node.first->right, (long long)2*currIndex + 2});
            }
            maxWidth = std::max(maxWidth, (rightMostIndex - leftMostIndex + 1));
        }
        return maxWidth;
    }
};
