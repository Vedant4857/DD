class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }

    // int minAddToMakeValid(string s) {
    //     int leftb = 0;
    //     int rightb = 0;

    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] == '(') {
    //             leftb++;
    //         } else if (s[i] == ')' && leftb) {
    //             leftb--;
    //         } else {
    //             rightb++;
    //         }
    //     }
    //     return (leftb + rightb);
    // }
};
