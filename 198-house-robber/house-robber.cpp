class Solution {
public:
    int ans(vector<int>& nums, int n, vector<int>& dp) {
        if(n==0){
            return nums[n];
        }
        if(n==1){
            return max(nums[0],nums[1]);
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = max(nums[n]+ans(nums,n-2,dp),ans(nums,n-1,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return ans(nums, n-1, dp);
    }
};