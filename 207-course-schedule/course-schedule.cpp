class Solution {
public:
    bool canFinish(int nu, vector<vector<int>>& pre) {
        vector<vector<int>> adj(nu);
        vector<int> inorder(nu);
        for (const auto& a : pre) {
            adj[a[1]].push_back(a[0]);
            inorder[a[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < nu; i++) {
            if (!inorder[i]) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nu--;

            for (auto neib : adj[node]) {
                inorder[neib]--;
                if (!inorder[neib]) {
                    q.push(neib);
                }
            }
        }
        return nu == 0;
    }
};