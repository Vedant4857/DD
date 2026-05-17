class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0;
        int product = 1;
        int n = nums.size();
        if (k <= 1) {
            return 0;
        }

        while (right < n) {
            product *= nums[right];

            while (product >= k) {
                product /= nums[left];
                left++;
            }

            count += (right - left + 1);
            right++;
        }
        return count;
    }
};