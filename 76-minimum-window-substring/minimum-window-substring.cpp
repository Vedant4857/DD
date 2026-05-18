class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> t_freq(128, 0);
        for (auto x : t) {
            t_freq[x]++;
        }
        int t_counter = t.size();
        vector<int> s_freq(128, 0);
        int left = 0, right = 0, s_counter = 0, startindex = 0,
            minsize = INT_MAX, n = s.size();

        while (right < n) {
            s_freq[s[right]]++;

            if (t_freq[s[right]] && s_freq[s[right]] <= t_freq[s[right]]) {
                s_counter++;
            }
            while (s_counter == t_counter) {
                if (right - left + 1 < minsize) {
                    minsize = right - left + 1;
                    startindex = left;
                }
                if (t_freq[s[left]] && s_freq[s[left]] <= t_freq[s[left]]) {
                    s_counter--;
                }

                s_freq[s[left]]--;
                left++;
            }
            right++;
        }
        return minsize == INT_MAX ? "" : s.substr(startindex, minsize);
    }
};