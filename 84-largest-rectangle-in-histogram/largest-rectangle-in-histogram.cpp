class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    

    stack<int>st;
    int n = heights.size();

    // Next smallest Right and Left

    vector<int>NSR(n);
    vector<int>NSL(n,-1);


    for(int i=0;i<n;i++){
        while(!st.empty()&&heights[i]<heights[st.top()]){
            NSR[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while(!st.empty()){
        NSR[st.top()] = n;
        st.pop();
    }


    // Next smallest element on Left side

    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&heights[i]<heights[st.top()]){
            NSL[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }


    int maxArea = 0;

    for(int i=0;i<n;i++){
        maxArea = max(maxArea,(NSR[i]-NSL[i]-1)*heights[i]);
    }


    return maxArea;



}
};