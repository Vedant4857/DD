class Solution {
public:
    bool isvalid(int i, int j, int row, int col) {
        if (i >= 0 && i < row && j >= 0 && j < col) {
            return 1;
        }
        return 0;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int x = entrance[0];
        int y = entrance[1];
        maze[x][y] = '+';
        int ans = 0;

        int row = maze.size();
        int col = maze[0].size();

        queue<pair<int, int>> q;
        q.push({x, y});

        while (!q.empty()) {
            int sz = q.size();
            ans++;

            while (sz--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                int r[4] = {1, 0, -1, 0};
                int c[4] = {0, 1, 0, -1};

                for (int k = 0; k < 4; k++) {
                    if (isvalid(i + r[k], j + c[k], row, col) &&
                        maze[i + r[k]][j + c[k]] == '.') {
                        if (i + r[k] == row - 1 || j + c[k] == col - 1 ||
                            i + r[k] == 0 || j + c[k] == 0) {
                            return ans;
                        }
                        maze[i + r[k]][j + c[k]] = '+';
                        q.push({i + r[k], j + c[k]});
                    }
                }
            }
        }
        return -1;
    }
};