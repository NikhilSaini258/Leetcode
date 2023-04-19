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

