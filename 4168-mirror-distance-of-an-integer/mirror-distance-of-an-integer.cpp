class Solution {
public:
    int mirrorDistance(int n) {
        int x = n;
        int sum = 0;
        while (x) {
            int rem = x % 10;
            sum = sum * 10 + rem;
            x /= 10;
        }
        return abs(sum - n);
    }
};