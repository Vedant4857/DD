class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v = rooms.size();
        vector<bool> vis(v);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neib : rooms[node]) {
                if (!vis[neib]) {
                    vis[neib] = 1;
                    q.push(neib);
                }
            }
        }
        for (auto x : vis) {
            if (!x) {
                return 0;
            }
        }
        return 1;
    }
};