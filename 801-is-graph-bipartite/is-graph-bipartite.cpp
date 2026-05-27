class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int v = graph.size();
        vector<int> colour(v, -1);

        for (int i = 0; i < v; i++) {
            if (colour[i] == -1) {
                q.push(i);
                colour[i] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto neib : graph[node]) {
                        if (colour[neib] == -1) {
                            colour[neib] = (colour[node] + 1) % 2;
                            q.push(neib);
                        } else if (colour[neib] == colour[node]) {
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};