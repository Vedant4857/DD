class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban;
        for (int x : banned) {
            ban.insert(x);
        }
        int count = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (ban.contains(i)) {
                continue;
            }
            sum += i;
            if (sum <= maxSum) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};