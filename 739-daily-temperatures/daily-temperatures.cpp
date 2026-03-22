class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        int n = t.size();
        vector<int> NGR(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && t[i] > t[st.top()]) {
                NGR[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return NGR;
    }
};