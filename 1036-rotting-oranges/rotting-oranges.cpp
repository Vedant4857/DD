class Solution {
public:
    bool isvalid(int i, int j, int row, int col) {
        if (i < row && j < col && i >= 0 && j >= 0) {
            return true;
        }
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int minutes = 0;

        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        while (!q.empty()) {
            int rot = q.size();
            minutes++;
            while (rot--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                int row[4] = {0, 1, -1, 0};
                int col[4] = {1, 0, 0, -1};

                for (int k = 0; k < 4; k++) {
                    if (isvalid(i + row[k], j + col[k], r, c) &&
                        grid[i + row[k]][j + col[k]] == 1) {
                        grid[i + row[k]][j + col[k]] = 2;
                        q.push({i + row[k], j + col[k]});
                    }
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return minutes == 0 ? 0 : minutes - 1;
    }
};