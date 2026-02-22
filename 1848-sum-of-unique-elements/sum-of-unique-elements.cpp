class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> vedant(101);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            vedant[nums[i]]++;
        }

        for (int i = 0; i < 101; i++) {
            if (vedant[i] == 1) {
                sum += i;
            }
        }
        return sum;
    }
};