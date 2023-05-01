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
    void traverseInorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
        traverseInorder(root->left, ans);
        ans.push_back(root->val);
        traverseInorder(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverseInorder (root, ans);
        return ans;
    }
};

// Morris In-Order Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                vec.push_back (curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    vec.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return vec;
    }
};
