class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long sum = 0;
        long long prev = nums[0];

        int n = nums.size();
        for (int i = 1; i < n; i++) {
            long long curr = nums[i] + sum;
            if (curr < prev) {
                long long x = prev - curr;
                curr += x;
                sum += x;
            }
            prev = curr;
        }
        return sum;
    }
};