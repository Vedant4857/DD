class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> freq;
        int count = 0;
        for (auto s : nums) {
            freq[s]++;
        }
        for (auto s : nums) {
            if (target.find(s) == 0) {
                string x = target.substr(s.size());
                count += freq[x];
                if (x == s) {
                    count--;
                }
            }
        }
        return count;
    }
};