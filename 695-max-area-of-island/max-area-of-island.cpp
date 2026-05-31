class Solution {
public:
    bool isvalid(int i, int j, int r, int c) {
        if (i >= 0 && i < r && j >= 0 && j < c) {
            return 1;
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int maxi = INT_MIN;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int count = 0;

                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }

                while (!q.empty()) {
                    int i = q.front().first;
                    int j = q.front().second;

                    q.pop();
                    count++;

                    int r[4] = {0, 0, 1, -1};
                    int c[4] = {1, -1, 0, 0};

                    for (int k = 0; k < 4; k++) {
                        if (isvalid(i + r[k], j + c[k], row, col) &&
                            grid[i + r[k]][j + c[k]] == 1) {
                            grid[i + r[k]][j + c[k]] = 0;
                            q.push({i + r[k], j + c[k]});
                        }
                    }
                }
                maxi = max(count, maxi);
            }
        }
        return maxi;
    }
};