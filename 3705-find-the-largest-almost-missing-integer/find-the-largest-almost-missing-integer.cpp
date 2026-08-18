class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> arr(maxi + 1, 0);
        for (int x : nums) {
            arr[x]++;
        }
        int onlyone = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                onlyone = i;
            }
        }
        if (k == 1) {
            return onlyone;
        }
        if (k == n) {
            return maxi;
        }
        if (k > 1 && k < n) {
            if (arr[nums[0]] == 1 && arr[nums[n - 1]] == 1) {
                return max(nums[0], nums[n - 1]);
            }
            if (arr[nums[0]] > 1 && arr[nums[n - 1]] == 1) {
                return nums[n - 1];
            }
            if (arr[nums[n - 1]] > 1 && arr[nums[0]] == 1) {
                return nums[0];
            }
        }
        return -1;
    }
};