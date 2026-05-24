class Solution {
public:
    vector<int> findOrder(int nu, vector<vector<int>>& pre) {
        vector<int> indegree(nu, 0);
        vector<vector<int>> adj(nu);
        for (const auto& a : pre) {
            adj[a[1]].push_back(a[0]);
            indegree[a[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < nu; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            nu--;

            for (int neib : adj[node]) {
                indegree[neib]--;
                if (!indegree[neib]) {
                    q.push(neib);
                }
            }
        }
        if (nu != 0) {
            return {};
        }
        return ans;
    }
};