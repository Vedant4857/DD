class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> postmin(n);
        int mini = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < mini) {
                mini = nums[i];
            }
            postmin[i] = mini;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = nums[i] > maxi ? nums[i] : maxi;
            if (maxi - postmin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};