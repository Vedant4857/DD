class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char x = arr[i][j];
                if (x >= '1' && x <= '9') {
                    int m = i + 1;
                    int n = j;
                    while (m < 9) {
                        if (arr[m][n] == x) {
                            return 0;
                        }
                        m++;
                    }
                    m = i;
                    n = j + 1;
                    while (n < 9) {
                        if (arr[m][n] == x) {
                            return 0;
                        }
                        n++;
                    }
                    int rs = (i / 3) * 3;
                    int cs = (j / 3) * 3;

                    for (int r = rs; r < rs + 3; r++) {
                        for (int c = cs; c < cs + 3; c++) {
                            if ((arr[r][c] == x) && (r != i || c != j)) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        return 1;
    }
};