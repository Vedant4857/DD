class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> dist;
        for (int x : nums) {
            dist.insert(x);
        }
        int distinct = dist.size();
        int count = 0;

        unordered_map<int, int> freq;
        int dist2 = 0, left = 0, right = 0;
        while (right < nums.size()) {
            freq[nums[right]]++;
            if (freq[nums[right]] == 1) {
                dist2++;
            }

            while (dist2 >= distinct) {
                count += nums.size() - right;
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    dist2--;
                }
                left++;
            }
            right++;
        }
        return count;
    }
};