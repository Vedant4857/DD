class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        // 10.  -1.   3.   -4.   -5.
        // 10.  9.   12.   8.    3
        // -5   -5   -5   -5    -5

        int n = nums.size();
        vector<long long> presum(n);
        vector<int> sufmin(n);
        int mini = INT_MAX;
        long long sum = 0, maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            presum[i] = sum;

            int j = n - 1 - i;
            mini = min(mini, nums[j]);
            sufmin[j] = mini;
        }

        for (int i = 0; i < n - 1; i++) {
            maxi = max(maxi, presum[i] - sufmin[i + 1]);
        }
        return maxi;
    }
};