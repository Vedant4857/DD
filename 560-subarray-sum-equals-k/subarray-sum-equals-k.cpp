class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int count = 0;
        int prefixsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixsum += nums[i];
            count += freq[prefixsum - k];
            freq[prefixsum]++;
        }
        return count;
    }
};