class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > 0 && a[i] < 0) {
                if (abs(a[i]) < st.top()) {
                    goto next_outer_iteration;
                } else if (abs(a[i]) > st.top()) {
                    st.pop();
                } else if (abs(a[i]) == st.top()) {
                    st.pop();
                    goto next_outer_iteration;
                }
            }

            st.push(a[i]);

        next_outer_iteration:;
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};