class Solution {
public:
    bool isvalid(int i, int j, int r, int c) {
        if (i >= 0 && i < r && j >= 0 && j < c) {
            return 1;
        }
        return 0;
    }
    void solve(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 'O') {
                q.push({i, 0});
                grid[i][0] = 'V';
            }
        }
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 'O') {
                q.push({0, i});
                grid[0][i] = 'V';
            }
        }
        for (int i = 0; i < row; i++) {
            if (grid[i][col - 1] == 'O') {
                q.push({i, col - 1});
                grid[i][col - 1] = 'V';
            }
        }
        for (int i = 0; i < col; i++) {
            if (grid[row - 1][i] == 'O') {
                q.push({row - 1, i});
                grid[row - 1][i] = 'V';
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
                    grid[i + r[k]][j + c[k]] == 'O') {
                    grid[i + r[k]][j + c[k]] = 'V';
                    q.push({i + r[k], j + c[k]});
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 'V') {
                    grid[i][j] = 'O';
                } else {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};