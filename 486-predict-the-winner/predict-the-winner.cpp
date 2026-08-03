class Solution {
public:
    int vedant(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i == j) {
            return arr[i];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int takefirst = arr[i] - vedant(arr, i + 1, j, dp);
        int takelast = arr[j] - vedant(arr, i, j - 1, dp);

        return max(takefirst, takelast);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return (vedant(nums, 0, n - 1, dp)) >= 0;
    }
};