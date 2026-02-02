class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size(), pre = 0, suf = 1;
        vector<int> LHP(n,0);

        while(suf<n){
            if(s[pre] == s[suf]){
                LHP[suf] =  pre + 1;
                pre++;
                suf++;
            }
            else{
                if(pre == 0){
                    LHP[suf] = 0;
                    suf++;
                }
                else{
                    pre = LHP[pre-1];
                }
            }
        }
        return s.substr(0,LHP[n-1]);
    }
};