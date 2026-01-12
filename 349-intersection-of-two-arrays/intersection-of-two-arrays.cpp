class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       set <int> vedant;
       sort(nums1.begin(), nums1.end());
       for(int x : nums2){
        if(binary_search(nums1.begin(),nums1.end(),x)) vedant.insert(x);
       }
       return vector<int>(vedant.begin(),vedant.end());
    }
};