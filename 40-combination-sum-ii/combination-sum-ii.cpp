class Solution {
public:
    void vedant(vector<int>& candidates, int index, int n, int sum,
                vector<int> &subans, int target, vector<vector<int>>& ans) {

        if (index == n || sum > target) {
            if (sum == target) {
                ans.push_back(subans);
            }
            return;
        }
        subans.push_back(candidates[index]);
        vedant(candidates, index + 1, n, sum + candidates[index], subans,
               target, ans);
        subans.pop_back();
        int j = index + 1;
        while (j < n && candidates[j] == candidates[index]) {
            j++;
        }
        vedant(candidates, j, n, sum, subans, target, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subans;
        sort(candidates.begin(), candidates.end());
        vedant(candidates, 0, candidates.size(), 0, subans, target, ans);

        return ans;
    }
};