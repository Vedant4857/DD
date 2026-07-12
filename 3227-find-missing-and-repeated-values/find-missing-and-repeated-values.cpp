class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> freq(2501, 0);
        int total = n * n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }
        int mis = 0, dup = 0;
        for (int i = 1; i <= total; i++) {
            if (freq[i] == 0) {
                mis = i;
            }
            if (freq[i] == 2) {
                dup = i;
            }
        }
        return {dup, mis};
    }
};