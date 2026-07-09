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
        vector<int>dp(n+1,-1);
        return ans(cost,n,dp);
    }
};