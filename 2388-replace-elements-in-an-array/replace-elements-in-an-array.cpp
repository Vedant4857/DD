class Solution {
public:
    vector<int> arrayChange(vector<int>& nums,
                            vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        int r = operations.size();

        for (int i = 0; i < r; i++) {
            if (mp.count(operations[i][0])) {
                int j = mp[operations[i][0]];
                nums[j] = operations[i][1];
                mp.erase(operations[i][0]);
                mp[operations[i][1]] = j;
            }
        }
        return nums;
    }
};