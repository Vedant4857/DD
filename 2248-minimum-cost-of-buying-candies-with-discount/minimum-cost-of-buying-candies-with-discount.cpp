class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        // 3. 5.  7. 9 11 14. 15. 18 20
        int sum = 0;
        int n = cost.size();
        if (n == 1) {
            return cost[0];
        }
        int i = n - 1;
        while (i >= 1) {
            sum += cost[i] + cost[i - 1];
            i = i - 3;
            // 2. 2. 5. 6. 7. 9.
            if (i < 0) {
                return sum;
            }
            if (i == 0) {
                return sum += cost[i];
            }
        }
        return sum;
    }
};