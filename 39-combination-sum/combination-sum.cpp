class Solution {
public:
    void vedant(vector<int>& c, vector<int>& subans, vector<vector<int>>& ans,
                int index, int sum, int n, int target) {
        if (sum == target) {
            ans.push_back(subans);
            return;
        }

        if (sum > target || index == n) {
            return;
        }

        vedant(c, subans, ans, index + 1, sum, n, target);
        subans.push_back(c[index]);
        vedant(c, subans, ans, index, sum + c[index], n, target);
        subans.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int> subans;
        vector<vector<int>> ans;
        int n = c.size();
        vedant(c, subans, ans, 0, 0, n, target);
        return ans;
    }
};