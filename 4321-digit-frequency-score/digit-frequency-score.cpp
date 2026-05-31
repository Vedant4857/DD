class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> freq;
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            freq[rem]++;
            n = n / 10;
        }
        for (auto pair : freq) {
            sum += pair.first * pair.second;
        }
        return sum;
    }
};