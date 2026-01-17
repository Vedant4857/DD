class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxelement = INT_MIN;
        int maindifff = 0;;

        for(int i = n-1;i>=0;i--){
            if(prices[i] > maxelement){
                maxelement = prices[i];
                continue;
            }
            int diff = maxelement - prices[i];
            maindifff = max(diff,maindifff);
        }
        return maindifff;
    }
};