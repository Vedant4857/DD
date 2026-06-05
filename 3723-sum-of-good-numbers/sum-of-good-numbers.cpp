class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[i] = nums[i];
        }

        for (int i = 0; i < n; i++) {
            int x = i - k;
            int y = i + k;
            if (x < 0 && y >= n) {
                sum += nums[i];
            } else if (x < 0 && nums[i] > mp[y]) {
                sum += nums[i];
            } else if (y >= n && nums[i] > mp[x]) {
                sum += nums[i];
            } else if (nums[i] > mp[y] && nums[i] > mp[x]) {
                sum += nums[i];
            }
        }
        return sum;
    }
};