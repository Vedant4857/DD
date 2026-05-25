class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_set<int> ved;
        vector<int> ans;

        for (int x : nums) {
            mini = min(x, mini);
            maxi = max(x, maxi);
            ved.insert(x);
        }
        for (int i = mini + 1; i < maxi; i++) {
            if (!ved.contains(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};