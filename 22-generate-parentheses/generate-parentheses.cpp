class Solution {
public:
    void vedant(int n, int open, int close, string x, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(x);
            return;
        }

        if (close > open || open > n) {
            return;
        }

        vedant(n, open + 1, close, x + '(', ans);
        vedant(n, open, close + 1, x + ')', ans);
    }
    vector<string> generateParenthesis(int n) {
        string x = "";
        vector<string> ans;
        vedant(n, 0, 0, x, ans);
        return ans;
    }
};