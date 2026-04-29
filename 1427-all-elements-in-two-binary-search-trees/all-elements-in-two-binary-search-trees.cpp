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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> ans;

        while (root1 || root2 || !s1.empty() || !s2.empty()) {
            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }
            while (root2) {
                s2.push(root2);
                root2 = root2->left;
            }

            if (s1.empty()) {
                TreeNode* a2 = s2.top();
                ans.push_back(a2->val);
                root2 = a2->right;
                s2.pop();
            } else if (s2.empty()) {
                TreeNode* a1 = s1.top();
                ans.push_back(a1->val);
                root1 = a1->right;
                s1.pop();
            } else {
                TreeNode* a1 = s1.top();
                TreeNode* a2 = s2.top();
                if (a1->val <= a2->val) {
                    ans.push_back(a1->val);
                    root1 = a1->right;
                    s1.pop();
                } else {
                    ans.push_back(a2->val);
                    root2 = a2->right;
                    s2.pop();
                }
            }
        }
        return ans;
    }
};