class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        if (s_size < p_size) {
            return {};
        }
        vector<int> need(26, 0);
        vector<int> got(26, 0);
        vector<int> ans;

        for (int i = 0; i < p_size; i++) {
            need[p[i] - 'a']++;
        }

        for (int i = 0; i < s_size; i++) {
            got[s[i] - 'a']++;

            if (i >= p_size) {
                got[s[i - p_size] - 'a']--;
            }

            if (got == need) {
                ans.push_back(i - p_size+1);
            }
        }
        return ans;
    }
};