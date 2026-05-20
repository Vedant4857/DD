class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
            maxi = max(maxi, candies[i]);
        }

        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxi) {
                result[i] = 1;
            } else {
                result[i] = 0;
            }
        }
        return result;
    }
};