class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mini = INT_MAX;
        for (int i = 1; i < n; i++) {
            mini = min(mini, nums[i] - nums[i - 1]);
        }
        return mini;
    }
};