class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();
        vector<pair<int, int>> arr2(n);
        for (int i = 0; i < n; i++) {
            arr2[i].first = arr[i];
            arr2[i].second = i;
        }
        sort(arr2.begin(), arr2.end());

        int j = 0;
        int prev = INT_MIN;
        for (int i = 0; i < n; i++) {
            int index = arr2[i].second;
            int val = arr2[i].first;

            if (val > prev) {
                prev = val;
                j++;
                arr[index] = j;
            } else if (val == prev) {
                arr[index] = j;
            }
        }
        return arr;
    }
};