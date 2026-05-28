class Solution {
public:
    bool isvalid(int i, int j, int r, int c) {
        if (i >= 0 && i < r && j >= 0 && j < c) {
            return 1;
        }
        return 0;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid.size();
        bool flag = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
                else{
                    flag = true;
                }
            }
        }
        if(!flag){
            return -1;
        }
        int count = 0;

        while (!q.empty()) {
            count++;
            int k = q.size();

            while (k--) {
                auto front = q.front();
                int i = front.first;
                int j = front.second;
                q.pop();

                int r[4] = {0, 0, 1, -1};
                int c[4] = {1, -1, 0, 0};

                for (int k = 0; k < 4; k++) {
                    if (isvalid(i + r[k], j + c[k], row, col) &&
                        grid[i + r[k]][j + c[k]] == 0) {
                        grid[i + r[k]][j + c[k]] = -1;
                        q.push({i + r[k], j + c[k]});
                    }
                }
            }
        }
        return count == 0 ? -1 : count - 1;
    }
};