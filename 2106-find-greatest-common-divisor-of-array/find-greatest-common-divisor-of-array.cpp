class Solution {
public:
    int findGCD(vector<int>& nums) {
        int x = *min_element(nums.begin(), nums.end());
        int y = *max_element(nums.begin(), nums.end());
        int mini = x;

        while (x) {
            if (y % x == 0 && mini % x == 0) {
                return x;
            }
            x--;
        }
        return 0;
    }
};