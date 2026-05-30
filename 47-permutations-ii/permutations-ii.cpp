class Solution {
public:
    void vedant(vector<int>& nums, int index, vector<vector<int>>& ans, int n) {

        if (index == n) {
            ans.push_back(nums);
            return;
        }

        vector<bool> used(21, 0);

        for (int i = index; i < n; i++) {
            if (!used[nums[i] + 10]) {
                used[nums[i]+10] = 1;
                swap(nums[i], nums[index]);
                vedant(nums, index + 1, ans, n);
                swap(nums[i], nums[index]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vedant(nums, 0, ans, n);
        return ans;
    }
};