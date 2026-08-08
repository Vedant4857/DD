class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int> ch1(26, 0);
        vector<int> ch2(26, 0);

        for (int i = 0; i < r.size(); i++) {
            ch1[r[i] - 'a']++;
        }
        for (int i = 0; i < m.size(); i++) {
            ch2[m[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (ch1[i] > ch2[i]) {
                return false;
            }
        }
        return true;
    }
};