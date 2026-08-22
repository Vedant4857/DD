class Solution {
public:
    bool isBalanced(string num) {
        int n = num.size();
        int evensum = 0, oddsum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evensum += num[i] - '0';
            } else {
                oddsum += num[i] - '0';
            }
        }
        if (oddsum == evensum) {
            return 1;
        }
        return 0;
    }
};