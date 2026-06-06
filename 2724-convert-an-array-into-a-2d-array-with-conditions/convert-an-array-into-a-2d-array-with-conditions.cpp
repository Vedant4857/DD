class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        vector<vector<int>> v;
        for (auto it : freq) {
            for (int i = 0; i < it.second; i++) {
                if (i >= v.size()) {
                    v.push_back({});
                }
                v[i].push_back(it.first);
            }
        }
        return v;
    }
};