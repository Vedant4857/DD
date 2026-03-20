class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftb = 0;
        int rightb = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftb++;
            } else if (s[i] == ')' && leftb) {
                leftb--;
            } else {
                rightb++;
            }
        }
        return (leftb + rightb);
    }
};