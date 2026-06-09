class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int len = 0;
        int ans = 0;

        for (int x : st) {
            if (st.find(x - 1) == st.end()) {
                len = 1;
                int y = x + 1;
                while (st.find(y) != st.end()) {
                    len++;
                    y++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};