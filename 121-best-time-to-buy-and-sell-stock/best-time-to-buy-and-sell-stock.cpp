class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prevminprice = prices[0];
        int profit = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] > prevminprice) {
                profit = max(profit, prices[i] - prevminprice);
            } else {
                prevminprice = prices[i];
            }
        }
        return profit;
    }
};