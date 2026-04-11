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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode *> st;
        vector<int>ans;
        st.push(root);

        while(!st.empty()){
            TreeNode * c = st.top();
            st.pop();
            ans.push_back(c->val);
            if(c->left){
                st.push(c->left);
            }
            if(c->right){
                st.push(c->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};