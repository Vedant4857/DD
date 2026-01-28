class Solution {
public:
    string sortSentence(string s) {
        int n = s.size();
        string ans = "";
        int num = 1;
        while (num <= 9){
            int j = n-1;
            while(j>=0 && s[j] != num + '0'){
                j--;
            }
            if (j < 0) break;
            j--;
            string xyz = "";

            while(j>=0 && s[j]!=' '){
                xyz += s[j];
                j--;
            }
            reverse(xyz.begin(),xyz.end());
            if (!ans.empty()) ans += ' ';
            ans += xyz;
            num++;
        }
        return ans;
    }
};