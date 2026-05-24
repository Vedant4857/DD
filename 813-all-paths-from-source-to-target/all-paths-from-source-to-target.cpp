class Solution {
public:
    void DFS(vector<vector<int>>& graph, vector<vector<int>>& ans,
             vector<int>& subans, int sour, int dest) {
        subans.push_back(sour);
        if (sour == dest) {
            ans.push_back(subans);
        } else {
            for (int neib : graph[sour]) {
                DFS(graph, ans, subans, neib, dest);
            }
        }
        subans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> ans;
        vector<int> subans;
        DFS(graph, ans, subans, 0, v - 1);
        return ans;
    }
};