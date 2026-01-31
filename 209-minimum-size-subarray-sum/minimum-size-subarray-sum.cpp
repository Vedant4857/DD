class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums[0]>=target) return 1;
        int n = nums.size(), i = 0, j= 1, sum = nums[i], mini = INT_MAX;
        bool found = false;
        while(j<n){
            sum += nums[j];
            while(sum>=target){
                mini = min(mini,(j-i + 1));
                sum -= nums[i];
                i++;
                found = true;
            }
            j++;
        }
        if (found) return mini;
        return 0;
    }
};