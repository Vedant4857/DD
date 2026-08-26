class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;
        int i = 0;
        int n = word.size();
        string ans = "";

        while (i < n) {
            st.push(word[i]);
            if (st.top() == ch) {
                while (st.size()) {
                    ans += st.top();
                    st.pop();
                }
                i++;
                while (i < n) {
                    ans += word[i];
                    i++;
                }
                break;
            }
            i++;
        }
        if (ans == "")
            return word;

        return ans;
    }
};