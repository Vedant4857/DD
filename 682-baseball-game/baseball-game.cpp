class Solution {
public:
    bool isNumber(string s) {
        if (s.empty())
            return false;
        int i = 0;
        if (s[0] == '-')
            i = 1;
        return i < s.size() && all_of(s.begin() + i, s.end(), ::isdigit);
    }
    int calPoints(vector<string>& o) {
        stack<int> st;
        for (int i = 0; i < o.size(); i++) {
            if (isNumber(o[i])) {
                st.push(stoi(o[i]));
            } else {
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
                }
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