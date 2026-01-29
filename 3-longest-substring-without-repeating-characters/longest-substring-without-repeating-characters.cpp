class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool freq[256] = {0};
        int start = 0;
        int end = 0;
        int n = s.size();
        int ans = 0;

        while(end<n){
            // already in the current window checking
            while(freq[s[end]]){
                freq[s[start]] = 0;
                start++;
            }
            freq[s[end]] = 1;
            end++;

            ans = max(ans,end-start);

        }
        return ans;
        
    }
};