class Solution {
public:
    // Merge Sort

    vector<int> mergesort(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            } else {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while (i < arr1.size()) {
            ans.push_back(arr1[i]);
            i++;
        }
        while (j < arr2.size()) {
            ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }
    vector<int> merge(vector<int>& arr, int start, int end) {
        if (start >= end) {
            return {arr[end]};
        }
        vector<int> first;
        vector<int> second;
        int p = start + (end - start) / 2;
        first = merge(arr, start, p);
        second = merge(arr, p + 1, end);

        return mergesort(first, second);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size() - 1;
        return merge(nums, 0, n);
    }
};