class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h) {
        long long sum = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            sum += (piles[i] + mid - 1) / mid;
        }
        return (sum <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEat(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};