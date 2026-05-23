class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if (nums[0] < nums[n - 1]) {
            count++;
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
                if (count > 1) {
                    return 0;
                }
            }
        }
        return 1;
    }
};