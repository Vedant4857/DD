class Solution {
public:

    int atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int n = nums.size();
        vector<int> freq(20001, 0);   // adjust size if constraint differs

        int left = 0, distinct = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            if (freq[nums[right]] == 0)
                distinct++;

            freq[nums[right]]++;

            while (distinct > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    distinct--;
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
