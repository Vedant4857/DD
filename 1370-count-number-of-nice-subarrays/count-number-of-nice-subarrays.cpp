class Solution {
public:
    int atleast(vector<int>& nums, int k) {
        int oddcounter = 0, left = 0, right = 0, n = nums.size(), ans = 0;

        while (right < n) {
            if (nums[right] % 2 != 0) {
                oddcounter++;
            }
            while (oddcounter >= k) {
                ans += n - right;
                if (nums[left] % 2 != 0) {
                    oddcounter--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atleast(nums, k) - atleast(nums, k + 1);
    }
};