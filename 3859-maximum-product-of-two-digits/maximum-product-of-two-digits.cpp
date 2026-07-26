class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while (n) {
            int rem = n % 10;
            arr.push_back(rem);
            n /= 10;
        }
        sort(arr.begin(), arr.end());
        int n1 = arr.size();
        int first = arr[n1 - 1] * arr[n1 - 2];
        int second = arr[0] * arr[1];
        return max(first, second);
    }
};