class Solution {
public:
    bool isvalid(int i, int j, int r, int c) {
        if (i >= 0 && i < r && j >= 0 && j < c) {
            return 1;
        }
        return 0;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 1) {
                grid[i][0] = 0;
                q.push({i, 0});
            }
        }
        for (int i = 0; i < row; i++) {
            if (grid[i][col - 1] == 1) {
                grid[i][col - 1] = 0;
                q.push({i, col - 1});
            }
        }
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 1) {
                grid[0][i] = 0;
                q.push({0, i});
            }
        }
        for (int i = 0; i < col; i++) {
            if (grid[row - 1][i] == 1) {
                grid[row - 1][i] = 0;
                q.push({row - 1, i});
            }
        }

        while (!q.empty()) {
            auto element = q.front();
            int i = element.first;
            int j = element.second;
            q.pop();

            int r[4] = {0, 0, -1, 1};
            int c[4] = {1, -1, 0, 0};

            for (int k = 0; k < 4; k++) {
                if (isvalid(i + r[k], j + c[k], row, col) &&
                    grid[i + r[k]][j + c[k]] == 1) {
                    grid[i + r[k]][j + c[k]] = 0;
                    q.push({i + r[k], j + c[k]});
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};