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
    int find(vector<int> inorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start,
                    int end, int& pos) {

        if (start > end || pos >= preorder.size()) {
            return NULL;
        }
        TreeNode* temp = new TreeNode(preorder[pos]);
        int index = find(inorder, start, end, preorder[pos]);
        pos++;
        temp->left = build(preorder, inorder, start, index - 1, pos);
        temp->right = build(preorder, inorder, index + 1, end, pos);

        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        return build(preorder, inorder, 0, inorder.size() - 1, pos);
    }
};