class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n <= 3) {
            return s;
        }
        string left = "";
        string middle = "";
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2 != 0) {
                middle = string(1, 'a' + i);
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        left = left + middle + right;
        return left;
    }
};