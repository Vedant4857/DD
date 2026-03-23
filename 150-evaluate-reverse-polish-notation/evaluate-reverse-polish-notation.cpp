class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                x = x + y;
                st.push(x);
            } else if (tokens[i] == "*") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                x = x * y;
                st.push(x);
            } else if (tokens[i] == "/") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                x = y / x;
                st.push(x);
            } else if (tokens[i] == "-") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                x = y - x;
                st.push(x);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};