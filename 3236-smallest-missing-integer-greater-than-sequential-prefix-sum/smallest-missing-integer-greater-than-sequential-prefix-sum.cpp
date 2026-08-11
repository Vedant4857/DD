class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        int prefixsum = nums[0];
        int i;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixsum += nums[i];
            } else {
                break;
            }
        }
        if (!st.count(prefixsum)) {
            return prefixsum;
        }
        for (int x = prefixsum; x <= 51; x++) {
            if (!st.count(x)) {
                return x;
            }
        }
        return nums[0]+1;
    }
};