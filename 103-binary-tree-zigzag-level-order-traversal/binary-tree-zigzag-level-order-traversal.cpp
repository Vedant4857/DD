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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        int count = 1;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> curr;
            int siz = q.size();
            for (int i = 0; i < siz; i++) {
                TreeNode* c = q.front();
                q.pop();
                curr.push_back(c->val);
                if (c->left) {
                    q.push(c->left);
                }
                if (c->right) {
                    q.push(c->right);
                }
            }
            if (count % 2 == 0) {
                reverse(curr.begin(), curr.end());
            }
            ans.push_back(curr);
            count++;
        }
        return ans;
    }
};