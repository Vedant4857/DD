class Solution {
public:
    int mincoins(int n, int amount, vector<int>& c, vector<vector<int>>& dp) {

        if (amount == 0) {
            return 0;
        }
        if (n == 0 || amount < 0) {
            return 1e9;
        }
        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }

        return dp[n][amount] = min(mincoins(n - 1, amount, c, dp),
                                   1 + mincoins(n, amount - c[n - 1], c, dp));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = mincoins(n, amount, coins, dp);
        if (ans == 1e9) {
            return -1;
        }
        return ans;
    }
};