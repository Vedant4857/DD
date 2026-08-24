class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) {
            total += x;
        }
        if (total % 2 != 0) {
            return 0;
        }
        int target = total / 2;
        vector<bool> dp(target + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
                if (dp[target])
                    return true;
            }
        }
        return dp[target];
    }
};