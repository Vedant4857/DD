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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        stack<TreeNode*> st;
        stack<bool> ts;
        vector<int> ans;

        st.push(root);
        ts.push(0);

        while (!st.empty()) {
            TreeNode* c = st.top();
            int x = ts.top();
            st.pop();
            ts.pop();

            if (x == 0) {
                if (c->right) {
                    st.push(c->right);
                    ts.push(0);
                }
                st.push(c);
                ts.push(1);
                if (c->left) {
                    st.push(c->left);
                    ts.push(0);
                }
            } else {
                ans.push_back(c->val);
            }
        }
        return ans;
    }
};