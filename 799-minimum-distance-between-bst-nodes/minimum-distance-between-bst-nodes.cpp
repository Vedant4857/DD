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
    void find(TreeNode* root, int& mindiff, int& preval) {
        if (!root) {
            return;
        }
        find(root->left, mindiff, preval);
        if (preval != INT_MIN) {
            mindiff = min(mindiff, root->val - preval);
        }
        preval = root->val;
        find(root->right, mindiff, preval);
    }
    int minDiffInBST(TreeNode* root) {
        int mindiff = INT_MAX;
        int preval = INT_MIN;
        find(root, mindiff, preval);
        return mindiff;
    }
};