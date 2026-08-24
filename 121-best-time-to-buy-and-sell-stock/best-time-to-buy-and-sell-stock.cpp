class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;
        int maxi = -1;
        for(int p : prices){
            mini = min(mini,p);
            maxi = max(maxi,p-mini);
        }
        return maxi;
    }
};