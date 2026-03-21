class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxarea = 0;

        for (int i = 0; i <= n; i++) {
            int currheight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currheight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int NSR = i;
                int NSL = st.empty() ? -1 : st.top();
                int width = NSR - NSL - 1;
                maxarea = max(maxarea, height * width);
            }
            st.push(i);
        }
        return maxarea;
    }
};