class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) {
            total += x;
        }
        if (abs(target) > total) {
            return 0;
        }
        if ((total + target) % 2 != 0) {
            return 0;
        }

        target = (total + target) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] + dp[i - num];
            }
        }
        return dp[target];
    }
};