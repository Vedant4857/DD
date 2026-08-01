class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool came = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                came = true;
            }
            if (s[i] == 'a') {
                if (came) {
                    return false;
                }
            }
        }
        return true;
    }
};