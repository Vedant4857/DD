class Solution {
public:
    int KMP(string& haystack, string& needle) {
        int n = haystack.size();
        int m = needle.size();

        vector<int> LPS(m, 0);
        int pre = 0, suf = 1;

        while (suf < m) {
            if (needle[suf] == needle[pre]) {
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

        pre = 0, suf = 0;

        while (pre < m && suf < n) {
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
        if (pre == m) {
            return 1;
        } else {
            return 0;
        }
    }

    int repeatedStringMatch(string a, string b) {
        int capacity = 1;
        string xyz = a;

        while (xyz.size() < b.size()) {
            xyz += a;
            capacity++;
        }

        if(KMP(xyz,b)){
            return capacity;
        }

        xyz += a;
        capacity++;
        if(KMP(xyz,b)){
            return capacity;
        }

        return -1;

    }
};