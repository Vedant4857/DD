class Solution {
public:
    string processStr(string s) {
        int i = 0;
        int n = s.size();
        string ans = "";
        while (i < n) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            } else if (s[i] == '*') {
                int y = ans.size();
                ans = ans.substr(0, y - 1);
            } else if (s[i] == '#') {
                ans += ans;
            } else if (s[i] == '%') {
                reverse(ans.begin(), ans.end());
            }
            i++;
        }
        return ans;
    }
};