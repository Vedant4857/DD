class Solution {
public:
    bool isvalid(int i, int j, int n) {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            return 1;
        }
        return 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 1;
        if (grid[0][0] == 1) {
            return -1;
        }

        if (n == 1) {
            return 1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        grid[0][0] = 1;

        while (!q.empty()) {
            int sz = q.size();
            ans++;

            while (sz--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                int r[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int c[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

                for (int k = 0; k < 8; k++) {
                    if (isvalid(i + r[k], j + c[k], n) &&
                        grid[i + r[k]][j + c[k]] == 0) {
                        if (i + r[k] == n - 1 && j + c[k] == n - 1) {
                            return ans;
                        }

                        grid[i + r[k]][j + c[k]] = 1;
                        q.push({i + r[k], j + c[k]});
                    }
                }
            }
        }
        return -1;
    }
};