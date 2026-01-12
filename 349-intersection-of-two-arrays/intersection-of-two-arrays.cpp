class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3;

        unordered_set <int> vedant;
        for(int i = 0;i<m;i++){
            if(vedant.count(nums1[i])) continue;
            vedant.insert(nums1[i]);
        }
        for(int i = 0;i<n;i++){
            if(vedant.count(nums2[i])){
                nums3.push_back(nums2[i]);
                vedant.erase(nums2[i]);
            }
        }
        return nums3;
    }
};