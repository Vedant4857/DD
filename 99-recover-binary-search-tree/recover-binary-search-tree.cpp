/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void vedant(TreeNode*& root, TreeNode*& prev, TreeNode*& first,
                TreeNode*& second) {
        if (!root) {
            return;
        }
        vedant(root->left, prev, first, second);
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;
                second = root;
            } else {
                second = root;
            }
        }
        prev = root;
        vedant(root->right, prev, first, second);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        vedant(root, prev, first, second);
        if (first)
            swap(first->val, second->val);
    }
};