class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int n = height.size();
        int j = n - 1;
        int maxi = 0;
        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;

            maxi = max(maxi, h * w);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxi;
    }
};