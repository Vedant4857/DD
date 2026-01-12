class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3;


        int i = 0;
        int j = 0;
        int k = 0;

        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        if(i==m){
            while(j<n){
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        else{
            while(i<m){
                nums3.push_back(nums1[i]);
                i++;
            }
        }

        int x = m+n;
        double median;

        if(x%2==1) median = nums3[x / 2];
        else median = (nums3[x/2 - 1] + nums3[x/2]) / 2.0;

        return median;


    }
};