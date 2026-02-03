class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        vector<int> LPS(n, 0);

        int pre = 0, suf = 1;

        while (suf < n) {
            if (needle[suf] == needle[pre]) {
                LPS[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    LPS[suf] = 0;
                    suf++;
                } else {
                    pre = LPS[pre - 1];
                }
            }
        }

        pre = 0, suf = 0;

        while (pre < n && suf < h) {
            if (needle[pre] == haystack[suf]) {
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
        if (pre == n) {
            return suf - pre;
        } else {
            return -1;
        }
    }
};