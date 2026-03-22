class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> NGR(n, -1);

        for (int i = 0; i < 2 * n; i++) {
            int index = i % n;
            while (!st.empty() && arr[index] > arr[st.top()]) {
                NGR[st.top()] = arr[index];
                st.pop();
            }
            st.push(index);
        }
        return NGR;
    }
};