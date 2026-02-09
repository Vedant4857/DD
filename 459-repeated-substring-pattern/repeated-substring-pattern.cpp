class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> LPS(n,0);
        int pre = 0, suf = 1;

        while(suf<n){
            if(s[pre] == s[suf]){
                LPS[suf] = pre + 1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    suf++;
                }
                else{
                    pre = LPS[pre-1];
                }
            }
        }
        if(LPS[n-1]==0) return 0;
        int repeating_char_num = n - LPS[n-1];
        return (n%repeating_char_num==0);
    }
};