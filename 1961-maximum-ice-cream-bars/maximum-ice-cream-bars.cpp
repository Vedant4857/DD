class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> prices(100001,0);
        // unordered_map<int,int>freq;

        for (int x : costs) {
            prices[x]++;
        }
        int count = 0;
        // number of icecream of that price
        for (int i = 1; i <= 100000; i++) {
            int canbuy = min(prices[i], coins / i);

            count += canbuy;
            coins -= canbuy * i;

            if (coins < i)
                break;
        }
        return count;
    }
};