class Solution {
public:

    int ans(vector<int>&c,int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = min(c[n-1]+ans(c,n-1,dp),c[n-2]+ans(c,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(3);

        dp[0] = 0;
        if(n==1){
            return cost[0];
        }
        if(n==2){
            return min(cost[0],cost[1]);
        }
        dp[1] = 0;
        dp[2] = min(cost[0],cost[1]);

        for(int i = 3;i<=n;i++){
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = min(cost[i-1]+dp[1],cost[i-2]+dp[0]);
        }
        return dp[2];
    }
};