class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n; i++) {
            if (i > farthest) {
                return 0;
            }
            int jump = i + nums[i];
            farthest = max(farthest, jump);
        }
        return 1;
    }
};