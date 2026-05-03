class Solution {
public:
    void heapify(vector<int>& arr, int i, int siz) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < siz && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < siz && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, largest, siz);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        for (int i = nums.size() / 2 - 1; i >= 0; i--) {
            heapify(nums, i, nums.size());
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }

        return nums;
    }
};