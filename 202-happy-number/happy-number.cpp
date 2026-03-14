class Solution {
public:
    int vedant(int n) {
        int sum = 0;

        while (n > 0) {
            int x = n % 10;
            sum += x * x;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = vedant(slow);
            fast = vedant(vedant(fast));
        } while (slow != fast);
        return (slow == 1);
    }
};