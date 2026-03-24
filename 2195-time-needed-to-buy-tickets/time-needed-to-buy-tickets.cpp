class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int n = arr.size();
        int x = arr[k];
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                if (i == k) {
                    count += x;
                } else if (i < k) {
                    count += (arr[i] >= x) ? x : arr[i];
                } else {
                    count += (arr[i] < x) ? arr[i] : (x - 1);
                }
            }
        }
        return count;
    }
};