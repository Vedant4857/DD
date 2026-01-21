class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        int x = row*col;
        vector<int> arr(x);
        vector<vector<int>> res(r, vector<int>(c));

        if(x != r*c) return mat;

        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                arr[i*col+j] = mat[i][j];
            }
        }

        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                res[i][j] = arr[i*c+j];
            }
        }
        return res;
    }
};