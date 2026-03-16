class Solution {
public:
    bool vedant(vector<int>& arr, int mid, int k) {
        int n = arr.size();
        int sum = 0;
        int count = 1;
        for (int i = 0; i < n; i++) {
            if (sum + arr[i] <= mid) {
                sum += arr[i];
            } else {
                count++;
                sum = arr[i];
            }
        }
        return (count <= k);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (vedant(weights, mid, days)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};