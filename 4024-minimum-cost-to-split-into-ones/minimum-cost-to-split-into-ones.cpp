class Solution {
public:
    int minCost(int n) {
        int cost = 0;
        while(n>=1){
            int x = 1;
            int y = n - 1;
            n = x * y;
            cost += n;
        }
        return cost;
    }
};