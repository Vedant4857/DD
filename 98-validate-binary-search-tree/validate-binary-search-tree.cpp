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
    bool valid(TreeNode* root, long long minval, long long maxval) {
        if (!root) {
            return 1;
        }
        if (root->val <= minval || root->val >= maxval) {
            return 0;
        }
        return (valid(root->left, minval, root->val) &&
                valid(root->right, root->val, maxval));
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};