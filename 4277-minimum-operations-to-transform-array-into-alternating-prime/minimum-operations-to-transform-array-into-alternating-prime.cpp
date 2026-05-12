class Solution {
public:
    bool isprime(int x) {
        if (x <= 1) {
            return false;
        }
        for (int i = 2; i<=sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                while (!isprime(nums[i])) {
                    nums[i] += 1;
                    count++;
                }
            } else {
                while (isprime(nums[i])) {
                    nums[i] += 1;
                    count++;
                }
            }
        }
        return count;
    }
};