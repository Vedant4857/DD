class Solution {
public:
    int calPoints(vector<string>& o) {
        stack<int> st;
        for (int i = 0; i < o.size(); i++) {
            if (o[i] == "C") {
                st.pop();
            } else if (o[i] == "D") {
                st.push(st.top() * 2);
            } else if (o[i] == "+") {
                int x = st.top();
                st.pop();
                int sum = x + st.top();
                st.push(x);
                st.push(sum);
            } else {
                st.push(stoi(o[i]));
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};