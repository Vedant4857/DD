class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int maxi = nums.size();
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        for (int i = 1; i <= maxi; i++) {
            if (!st.contains(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};