class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        freq[0] = 1;
        int prefixsum = 0;
        int rem;
        for (int x : nums) {
            prefixsum += x;
            rem = ((prefixsum % k) + k) % k;
            count += freq[rem];
            freq[rem]++;
        }
        return count;
    }
};