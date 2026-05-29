class Solution {
public:
    bool isvalid(int i, int j, int row, int col) {
        if (i < row && j < col && i >= 0 && j >= 0) {
            return true;
        }
        return 0;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    isWater[i][j]=0;

                } else {
                    isWater[i][j] = -1;
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            int r[4] = {0, 0, 1, -1};
            int c[4] = {1, -1, 0, 0};

            for (int k = 0; k < 4; k++) {
                if (isvalid(i + r[k], j + c[k], row, col) &&
                    isWater[i + r[k]][j + c[k]] == -1) {
                    isWater[i + r[k]][j + c[k]] = isWater[i][j] + 1;
                    q.push({i + r[k], j + c[k]});
                }
            }
        }
        return isWater;
    }
};