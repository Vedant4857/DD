class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int count = 0;
        while (left < right) {
            if (nums[left] == 0 && nums[right]) {
                count++;
                left++;
                right--;
            }
            if (nums[left] != 0) {
                left++;
            }
            if (nums[right] == 0) {
                right--;
            }
        }
        return count;
    }
};