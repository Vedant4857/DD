class Solution {
public:
    int canShip(vector<int>& weights, int mid, int days) {
        int sum = 0;
        int day = 1;

        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            } else {
                if (day < days) {
                    day++;
                    sum = weights[i];
                } else
                    return 0;
            }
        }
        return 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};