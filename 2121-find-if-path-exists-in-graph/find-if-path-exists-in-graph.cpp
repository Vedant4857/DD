class Solution {
public:
    bool DFS(vector<vector<int>>&adj,vector<bool>&vis,int sour,int dest){
        if(sour==dest){
            return 1;
        }
        vis[sour] = 1;

        for(auto neib: adj[sour]){
            if(!vis[neib]){
                if(DFS(adj,vis,neib,dest)){
                    return 1;
                }
            }
        }
        return 0;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,0);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return DFS(adj,visited,source,destination);
    }
};