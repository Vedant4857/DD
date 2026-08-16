class Solution {
public:
    int distributeCandies(vector<int>& c) {
        int n = c.size();
        int half = n / 2;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(c[i]);
        }
        int available = st.size();
        if (available < half) {
            return available;
        }
        return half;
    }
};