class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();

        reverse(s.begin(), s.end());
        string ans = "";
        int i = 0;

        while (i < size) {
            string x = "";
            while (i < size && s[i] == ' ') {
                i++;
            }
            if (i >= size) break;
            while (i < size && s[i] != ' ') {
                x = x + s[i];
                i++;
            }
            reverse(x.begin(), x.end());
            if (!ans.empty()) ans += ' ';
            ans += x;
        }
        return ans;
    }
};