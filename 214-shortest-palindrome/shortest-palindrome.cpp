class Solution {
public:
    string shortestPalindrome(string x) {
        int n = x.size();
        string temp = x;
        reverse(temp.begin(), temp.end());
        string s = x;
        s = s + '#' + temp;
        int pre = 0, suf = 1;
        vector<int> LPS(s.size(), 0);

        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                LPS[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    suf++;
                } else {
                    pre = LPS[pre - 1];
                }
            }
        }
        // if (n - LPS[s.size() - 1] >= 0) {
        //     return n - LPS[s.size() - 1];
        // }
        // return 0;

        int pal_length = LPS.back();
        string add = x.substr(pal_length);
        reverse(add.begin(),add.end());
        return add + x;
    }
};