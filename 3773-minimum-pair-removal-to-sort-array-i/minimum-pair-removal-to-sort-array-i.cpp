class Solution {
public:
    bool isnotsorted(vector<int> nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                return 1;
            }
        }
        return 0;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while (isnotsorted(nums)) {
            int minsum = INT_MAX;
            int idx = 0;
            for (int i = 1; i < nums.size(); i++) {
                int sum = nums[i] + nums[i - 1];
                if (sum < minsum) {
                    minsum = nums[i] + nums[i - 1];
                    idx = i - 1;
                }
            }
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            operations++;
        }
        return operations;
    }
};