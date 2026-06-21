class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;
        sort(costs.begin(), costs.end());
        for (int x : costs) {
            coins -= x;
            if (coins < 0) {
                return count;
            }
            count++;
        }
        return count;
    }
};