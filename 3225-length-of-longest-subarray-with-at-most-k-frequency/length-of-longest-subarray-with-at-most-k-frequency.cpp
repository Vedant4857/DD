class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        int counts = st.size();
        int ans = 0;

        unordered_map<int, int> freq;

        int left = 0, right = 0;

        int count = 0;
        while (right < n) {
            freq[nums[right]]++;
            if (freq[nums[right]] == 1) {
                count++;
            }
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    count--;
                }
                left++;
            }
            ans = max(ans, (right - left) + 1);

            right++;
        }
        return ans;
    }
};