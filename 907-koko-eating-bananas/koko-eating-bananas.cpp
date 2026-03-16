class Solution {
public:
    bool vedant(vector<int>& arr, int mid, int h) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (arr[i] + mid - 1) / mid;
        }
        return (sum <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (vedant(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};