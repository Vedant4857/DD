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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int siz = q.size();
            for (int i = 0; i < siz; i++) {
                TreeNode* c = q.front();
                q.pop();
                if (i == siz - 1) {
                    ans.push_back(c->val);
                }
                if (c->left) {
                    q.push(c->left);
                }
                if (c->right) {
                    q.push(c->right);
                }
            }
        }
        return ans;
    }
};