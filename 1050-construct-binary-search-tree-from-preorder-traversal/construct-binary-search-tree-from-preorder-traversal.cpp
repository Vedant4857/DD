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
    TreeNode* vedant(vector<int>& preorder, int& index, int mini, int maxi) {
        if (index >= preorder.size() || preorder[index] < mini ||
            preorder[index] > maxi) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[index]);
        index++;
        node->left = vedant(preorder, index, mini, node->val);
        node->right = vedant(preorder, index, node->val, maxi);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return vedant(preorder, index, INT_MIN, INT_MAX);
    }
};