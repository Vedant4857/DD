class Solution {
public:
    int maxDistinct(string s) {
        int n = s.size();
        int count = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                count++;
            }
        }
        return count;
    }
};