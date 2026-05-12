class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            string x = to_string(nums[i]);
            int j = 0;
            char dig = 48 + digit;
            while (j < x.size()) {
                if (x[j] == dig) {
                    count++;
                }
                j++;
            }
        }
        return count;
    }
};