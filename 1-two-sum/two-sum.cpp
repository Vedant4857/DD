class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (mp.find(t) != mp.end()) {
                if (i != mp[t]) {
                    return {mp[t], i};
                }
            }
        }
        return {-1, -1};
    }
};