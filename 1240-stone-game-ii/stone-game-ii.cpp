class Solution {
public:
    int dp[101][101];
    int vedant(int i, int M, vector<int>& piles) {
        int n = piles.size();

        if (i >= n) {
            return 0;
        }
        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int remaining = 0;
        for (int k = i; k < n; k++) {
            remaining += piles[k];
        }
        int best = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int opponent = vedant(i + X, max(M, X), piles);

            best = max(best, remaining - opponent);
        }
        return dp[i][M] = best;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return vedant(0, 1, piles);
    }
};