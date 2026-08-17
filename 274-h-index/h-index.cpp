class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int maxi = *max_element(c.begin(), c.end());
        vector<int> arr(maxi + 1, 0);

        for (int x : c) {
            arr[x]++;
        }

        int count = 0;
        for (int i = maxi; i >= 0; i--) {
            count += arr[i];
            arr[i] = count;
            if (arr[i] >= i) {
                return i;
            }
        }
        return 0;
    }
};