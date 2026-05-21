class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) {
            return false;
        }
        int x;
        int prefixsum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            prefixsum += nums[i];
            x = prefixsum % k;
            if (mp.count(x)) {
                if (i - mp[x] >= 2) {
                    return true;
                }
            } else {
                mp[x] = i;
            }
        }
        return false;
    }
};