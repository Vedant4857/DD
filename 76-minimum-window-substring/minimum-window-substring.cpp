class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);
        vector<int> freq2(256, 0);

        int required = 0, formed = 0;
        int i = 0, j = 0;
        int mini = INT_MAX, start = 0;

        // Build frequency map for t
        for (int k = 0; k < t.size(); k++) {
            if (freq[t[k]] == 0)
                required++;
            freq[t[k]]++;
        }

        // Sliding window
        while (j < s.size()) {
            if (freq[s[j]] > 0) {
                freq2[s[j]]++;

                if (freq2[s[j]] == freq[s[j]]) {
                    formed++;
                }
            }

            // Shrink window
            while (formed == required) {
                if (j - i + 1 < mini) {
                    mini = j - i + 1;
                    start = i;
                }

                if (freq[s[i]] > 0) {
                    freq2[s[i]]--;

                    if (freq2[s[i]] < freq[s[i]])
                        formed--;
                }
                i++;
            }
            j++;
        }

        return (mini == INT_MAX) ? "" : s.substr(start, mini);
    }
};
