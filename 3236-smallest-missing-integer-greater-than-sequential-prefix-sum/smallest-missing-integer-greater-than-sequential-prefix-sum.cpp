class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<bool> st(52, 0);
        for (int x : nums) {
            st[x] = 1;
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
        if(prefixsum>51){
            return prefixsum;
        }
        if (!st[prefixsum]) {
            return prefixsum;
        }
        for (int x = prefixsum; x <= 51; x++) {
            if (!st[x]) {
                return x;
            }
        }
        return nums[0] + 1;
    }
};