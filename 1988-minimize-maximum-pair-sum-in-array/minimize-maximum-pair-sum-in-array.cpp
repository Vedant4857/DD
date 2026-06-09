class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int sum = nums[i] + nums[n - 1 - i];
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};