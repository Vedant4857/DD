class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n);
        vector<int> mini(n);

        int minv = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < minv) {
                minv = nums[i];
            }
            mini[i] = minv;
        }

        int maxv = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxv) {
                maxv = nums[i];
            }
            maxi[i] = maxv;
            if (maxi[i] - mini[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};