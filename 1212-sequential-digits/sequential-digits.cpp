class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str;
        vector<int> ans;
        vector<int> ans2;

        for (int i = 1; i <= 9; i++) {
            str = "";
            string first;
            string second = "";
            for (int j = i + 1; j <= 9; j++) {
                first = to_string(i);
                second += to_string(j);
                str = first + second;
                int num = stoi(str);
                ans.push_back(num);
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] >= low && ans[i] <= high) {
                ans2.push_back(ans[i]);
            }
        }
        sort(ans2.begin(), ans2.end());
        return ans2;
    }
};