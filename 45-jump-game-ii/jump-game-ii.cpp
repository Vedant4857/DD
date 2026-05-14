class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int farthest = 0, currentend = 0, jumps = 0;
        for (int i = 0; i < n; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentend) {
                currentend = farthest;
                jumps++;
            }
            if (currentend >= n - 1) {
                return jumps;
            }
        }
        return jumps;
    }
};