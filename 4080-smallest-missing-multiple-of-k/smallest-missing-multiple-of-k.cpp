class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
           for (int x : nums) { st.insert(x); }
        for (int i = 1; i <= 101; i++) {
            if (!st.contains(k * i)) {
                return k * i;
            }
        }
        return 0;
    }
};