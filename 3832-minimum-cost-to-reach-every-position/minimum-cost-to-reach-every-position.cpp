class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int mini = cost[0];
        for(int i = 0;i<cost.size();i++){
            mini = min(mini,cost[i]);
            cost[i] = mini;
        }
        return cost;
    }
};