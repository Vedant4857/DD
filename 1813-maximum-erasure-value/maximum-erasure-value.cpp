class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int sum = 0, maxi = 0;
        unordered_map<int, int> freq;

        while (right < n) {
            freq[nums[right]]++;

            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            sum += nums[right];
            maxi = max(maxi, sum);
            right++;
        }
        return maxi;
    }
};