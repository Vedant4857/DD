class Solution {
public:
    void DFS(vector<vector<int>>& isC, int n, vector<bool>& vis, int node) {
        vis[node] = 1;

        for (int j = 0; j < n; j++) {
            if (isC[node][j] == 1 && !vis[j]) {
                DFS(isC, n, vis, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visi(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visi[i]) {
                count++;
                DFS(isConnected, n, visi, i);
            }
        }
        return count;
    }
};