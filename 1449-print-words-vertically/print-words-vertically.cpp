class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        int n = s.size();
        int i = 0;
        while (i < n) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            words.push_back(word);
            i++;
        }

        int maxleng = 0;
        int siz = words.size();
        for (int i = 0; i < siz; i++) {
            int leng = words[i].size();
            maxleng = max(maxleng, leng);
        }

        vector<string> ans;
        for (int i = 0; i < maxleng; i++) {
            string word1 = "";

            for (auto w : words) {
                if (i < w.size()) {
                    word1 += w[i];
                } else {
                    word1 += ' ';
                }
            }

            while (!word1.empty() && word1.back() == ' ') {
                word1.pop_back();
            }
            ans.push_back(word1);
        }
        return ans;
    }
};