class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        unordered_set<int> row(r);
        unordered_set<int> col(c);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (row.find(i) != row.end())
                    matrix[i][j] = 0;
                else if (col.find(j) != col.end())
                    matrix[i][j] = 0;
                else
                    continue;
            }
        }
    }
};