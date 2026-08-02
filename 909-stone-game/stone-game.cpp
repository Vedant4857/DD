class Solution {
public:
    int vedant(vector<int>& piles, int i, int j, vector<vector<int>>& dp) {
        if (i == j) {
            return piles[i];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int takefirst = piles[i] - vedant(piles, i + 1, j, dp);
        int takelast = piles[j] - vedant(piles, i, j - 1, dp);

        return dp[i][j] = max(takefirst, takelast);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return (vedant(piles, 0, n - 1, dp)) > 0;
    }
};