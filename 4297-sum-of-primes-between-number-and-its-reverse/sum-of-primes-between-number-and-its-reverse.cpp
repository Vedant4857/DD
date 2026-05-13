class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> s(n + 1, true);
        if (n >= 0)
            s[0] = 0;
        if (n >= 1)
            s[1] = 0;

        for (int i = 2; i * i <= n; i++) {
            if (s[i]) {
                for (int j = i * i; j <= n; j += i) {
                    s[j] = 0;
                }
            }
        }
        return s;
    }
    int sumOfPrimesInRange(int n) {
        int x = n;
        int sum = 0;
        while (x >= 1) {
            int y = x % 10;
            sum = sum * 10 + y;
            x = x / 10;
        }
        int mini = min(n, sum);
        int maxi = max(n, sum);
        vector<bool> primee = sieve(maxi);

        int sumo = 0;
        for (int i = mini; i <= maxi; i++) {
            if (primee[i]) {
                sumo += i;
            }
        }
        return sumo;
    }
};