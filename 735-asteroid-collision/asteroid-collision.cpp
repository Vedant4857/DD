class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            bool push = true;
            while (!st.empty() && st.top() > 0 && a[i] < 0) {
                if (abs(a[i]) < st.top()) {
                    push = false;
                    break;
                } else if (abs(a[i]) > st.top()) {
                    st.pop();
                } else if (abs(a[i]) == st.top()) {
                    st.pop();
                    push = false;
                    break;
                }
            }
            if (push) {
                st.push(a[i]);
            }
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