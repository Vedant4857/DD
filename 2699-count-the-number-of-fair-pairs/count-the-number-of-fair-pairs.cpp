class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        //.   0.  1.  4.  4.  5.   7.
        sort(nums.begin(), nums.end());
        long long up = 0, lo = 0;
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (nums[i] + nums[j] > upper) {
                j--;
            } else {
                up += j - i;
                i++;
            }
        }

        i = 0, j = n-1;
        while (i < j) {
            if (nums[i] + nums[j] >= lower) {
                j--;
            } else {
                lo += j - i;
                i++;
            }
        }
        return (up - lo);
    }
};