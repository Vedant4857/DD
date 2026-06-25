class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.size() && st.top().first == s[i]) {
                if (st.top().second == k - 1) {
                    for (int i = 0; i < k - 1; i++) {
                        st.pop();
                    }
                } else {
                    st.push({s[i], (st.top().second) + 1});
                }
            } else {
                st.push({s[i], 1});
            }
        }

        string str = "";
        while (!st.empty()) {
            str += st.top().first;
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};