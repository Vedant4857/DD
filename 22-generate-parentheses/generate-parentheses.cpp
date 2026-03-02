class Solution {
public:
    void vedant(int n, int open, int close, string &x, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(x);
            return;
        }
        if (open < n) {
            x.push_back('(');
            vedant(n, open + 1, close, x, ans);
            x.pop_back();
        }
        if (close < open) {
            x.push_back(')');
            vedant(n, open, close + 1, x, ans);
            x.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string x;
        vedant(n, 0, 0, x, ans);
        return ans;
    }
};