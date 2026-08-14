class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_set<int> st;
        unordered_map<int, int> freq;
        for (auto ch : s) {
            st.insert(ch);
        }
        int maxi = 0;

        int counts = st.size();

        int right = 0, left = 0;
        int n = s.size();
        int count = 0;

        while (right < n) {
            freq[s[right]]++;
            if (freq[s[right]] == 1) {
                count++;
            }

            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    count--;
                }
                left++;
            }

            maxi = max(maxi, (right - left) + 1);

            right++;
        }
        return maxi;
    }
};