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
    int find(vector<int>& inorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start,
                    int end, int& pos) {

        if (pos < 0 || start > end) {
            return NULL;
        }
        TreeNode* temp = new TreeNode(postorder[pos]);
        int index = find(inorder, start, end, postorder[pos]);
        pos--;
        temp->right = build(inorder, postorder, index + 1, end, pos);
        temp->left = build(inorder, postorder, start, index - 1, pos);

        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, pos);
    }
};