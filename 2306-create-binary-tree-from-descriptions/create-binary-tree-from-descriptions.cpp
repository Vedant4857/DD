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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        for (auto& x : descriptions) {
            int parent = x[0];
            int child = x[1];
            int isLeft = x[2];

            if (!mp[parent]) {
                mp[parent] = new TreeNode(parent);
            }
            if (!mp[child]) {
                mp[child] = new TreeNode(child);
            }
            if (isLeft) {
                mp[parent]->left = mp[child];
            }
            if (!isLeft) {
                mp[parent]->right = mp[child];
            }
            children.insert(child);
        }

        for (auto& it : descriptions) {
            int p = it[0];

            if (children.find(p) == children.end()) {
                return mp[p];
            }
        }
        return nullptr;
    }
};