class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        int sum2 = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int totalsum = 0;

        for(int i = 0;i<n;i++){
            sum1 += nums[i];
            maxi = max(sum1,maxi);
            if(sum1<0) sum1 = 0;

            sum2 += nums[i];
            mini = min(sum2,mini);
            if(sum2>0) sum2 = 0;

            totalsum += nums[i];
        }
        if(mini == totalsum) return maxi;
        return max(maxi,totalsum - mini);
    }
};