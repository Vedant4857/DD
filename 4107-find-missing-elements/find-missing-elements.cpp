class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = nums[0];
        vector<int> ans;
        unordered_set<int> st;
        int n = nums.size();
        int x = nums[n - 1];
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (int j = k; j <= x; j++) {
            if (st.find(j) == st.end()) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};