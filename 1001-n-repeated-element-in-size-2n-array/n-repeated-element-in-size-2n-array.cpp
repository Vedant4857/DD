class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int x : nums) {
            freq[x]++;
        }
        int maxi = 0;
        int num;
        for (auto y : freq) {
            if (maxi < y.second) {
                maxi = y.second;
                num = y.first;
            }
        }
        return num;
    }
};