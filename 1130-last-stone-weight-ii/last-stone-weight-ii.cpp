class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += stones[i];
        }
        int target = total / 2;
        vector<int> dp(target + 1, 0);

        for (int stone : stones) {
            for (int i = target; i >= stone; i--) {
                dp[i] = max(dp[i], stone + dp[i - stone]);
            }
        }
        return total - 2 * dp[target];
    }
};