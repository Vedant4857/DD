class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int ssiz = s.size();
        int tsiz = t.size();

        int i = 0, j = 0;
        while (i < ssiz && j < tsiz) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                return t[i];
            }
        }
        return t[tsiz - 1];
    }
};