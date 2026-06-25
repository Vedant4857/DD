class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i] - 1;
            }
        }

        for (int r = 1; r <= n; r++) {
            for (int l = 0; l < r; l++) {
                if (prefix[r] > prefix[l]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};