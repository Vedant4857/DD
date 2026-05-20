class Solution {
public:
    string discountPrices(string s, int discount) {
        string str;
        int j = 0;
        while (j < s.size()) {
            if (s[j] == '$' && (j == 0 || s[j - 1] == ' ')) {
                string realstr = "";
                string numy = "";
                realstr += '$';
                j++;
                while (j < s.size() && isdigit(s[j])) {
                    realstr += s[j];
                    numy += s[j];
                    j++;
                }
                if (!numy.empty() && (j == s.size() || s[j] == ' ')) {
                    long long original = stoll(numy);
                    double nu = original;
                    nu = nu - ((nu / 100.0) * discount);
                    stringstream ss;
                    ss << fixed << setprecision(2) << nu;
                    str += '$';
                    str += ss.str();
                } else {
                    str += realstr;
                }
            } else {
                while (j < s.size() && s[j] != ' ') {
                    str += s[j];
                    j++;
                }
            }
            if (j < s.size() && s[j] == ' ') {
                str += ' ';
                j++;
            }
        }
        return str;
    }
};