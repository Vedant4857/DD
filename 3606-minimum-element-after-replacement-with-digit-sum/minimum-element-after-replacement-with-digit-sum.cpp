class Solution {
public:
    int minElement(vector<int>& nums) {
        int sum = 0;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int sum = 0;
            while (x) {
                int rem = x % 10;
                sum = sum + rem;
                x = x / 10;
            }
            mini = min(sum, mini);
        }
        return mini;
    }
};