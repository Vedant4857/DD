class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        int LeftRightMin;
        int sum = 0;
 
        for(int i = 1;i<n-1;i++){
            leftMax[i] = max(leftMax[i-1],height[i]);
            rightMax[n-1-i] = max(rightMax[n-i],height[n-1-i]);
        }

        for(int i =1;i<n-1;i++){
            LeftRightMin = min(leftMax[i-1],rightMax[i+1]);
            if(LeftRightMin > height[i]) sum += LeftRightMin - height[i];
        }
        return sum;
    }
};