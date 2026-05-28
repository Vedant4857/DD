class Solution {
public:
    bool isvalid(int i, int j, int r, int c) {
        if (i >= 0 && i < r && j >= 0 && j < c) {
            return 1;
        }
        return 0;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int color1 = image[sr][sc];
        if (color1 == color) {
            return image;
        }
        queue<pair<int, int>> q;
        int row = image.size();
        int col = image[0].size();
        image[sr][sc] = color;

        q.push({sr, sc});

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int rr[4] = {0, 0, -1, 1};
            int cc[4] = {1, -1, 0, 0};

            for (int k = 0; k < 4; k++) {
                if (isvalid(r + rr[k], c + cc[k], row, col) &&
                    image[r + rr[k]][c + cc[k]] == color1) {
                    image[r + rr[k]][c + cc[k]] = color;
                    q.push({r + rr[k], c + cc[k]});
                }
            }
        }
        return image;
    }
};