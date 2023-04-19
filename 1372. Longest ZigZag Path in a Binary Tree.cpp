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
    /*
                    rootNode
         leftNode            rightNode
        forwardSlope        backwardSlope
    */
    struct myPair {
        int forwardSlope = -1;
        int backwardSlope = -1;
        int maxLen = 0;
    };
    myPair solve (TreeNode* node) {
        myPair out;
        if (node == nullptr) {
            return out;
        }
        myPair left = solve (node->left);
        myPair right = solve (node->right);
        out.maxLen = std::max (std::max (left.maxLen, right.maxLen), 
                    std::max(left.backwardSlope, right.forwardSlope) + 1
                );
        out.forwardSlope = left.backwardSlope + 1;
        out.backwardSlope = right.forwardSlope + 1;
        return out;
    }
    int longestZigZag(TreeNode* root) {
        return solve(root).maxLen;
    }
};

// Compact Solution, but not much readable
class Solution {
public:
    /*
                    rootNode
         leftNode            rightNode
        forwardSlope        backwardSlope
    */
    vector<int> solve (TreeNode* node) {
        vector<int> out {-1, -1, 0};
        if (node == nullptr) {
            return out;
        }
        auto left = solve (node->left);
        auto right = solve (node->right);
        out[2] = std::max (
                    std::max (left[2], right[2]), 
                    std::max(left[1], right[0]) + 1
                );
        out[0] = left[1] + 1;
        out[1] = right[0] + 1;
        return out;
    }
    int longestZigZag(TreeNode* root) {
        return solve(root)[2];
    }
};
