class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size();
        int col = image[0].size();

        for (int i = 0; i < row; i++) {
            reverse(image[i].begin(), image[i].end());
            for(int j =0;j<col;j++){
                if(image[i][j]==0) image[i][j]=1;
                else image[i][j]=0;
            }
        }
        return image;
    }
};