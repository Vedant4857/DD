class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_set<int> v(n);
        for (int x : nums1) {
            v.insert(x);
        }
        for (int x : nums2) {
            if (v.count(x)) {
                return x;
            }
        }
        return -1;
    }
};