class Solution {
public:
    void vedant(vector<int>& nums, vector<int>& subans,
                vector<vector<int>>& ans, int n, vector<bool>& vis) {
        if (subans.size() == n) {
            ans.push_back(subans);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                subans.push_back(nums[i]);
                vedant(nums, subans, ans, n, vis);
                subans.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subans;
        vector<bool> vis(n, 0);
        vedant(nums, subans, ans, n, vis);
        return ans;
    }
};