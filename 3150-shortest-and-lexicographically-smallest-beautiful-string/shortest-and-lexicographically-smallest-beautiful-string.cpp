class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0, ones = 0;
        int n = s.size();
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') {
                ones++;
            }

            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {

                while (s[left] == '0') {
                    left++;
                }
                string curr = s.substr(left, right - left + 1);

                if (ans == "") {
                    ans = curr;
                } else if (ans.size() > curr.size()) {
                    ans = curr;
                } else if (ans.size() == curr.size() && ans > curr) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};