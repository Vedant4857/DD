class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = 1;
        if (n > 1) {
            dp[2] = 2;
        }

        if (n <= 2) {
            return dp[n];
        }

        for (int i = 3; i <= n; i++) {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[0] + dp[1];
        }
        return dp[2];
    }
};