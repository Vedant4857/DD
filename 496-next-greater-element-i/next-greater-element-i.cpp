class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> vedant;

        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                vedant[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while (!st.empty()) {
            vedant[st.top()] = -1;
            st.pop();
        }
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = vedant[nums1[i]];
        }
        return ans;
    }
};