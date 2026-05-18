class Solution {
public:
    int atmost(vector<int>& nums, int goal){
        if (goal < 0) return 0;
        int left = 0, right = 0, n = nums.size(),sum = 0,ans=0;

        while(right<n){
            sum += nums[right];

            while(sum>goal){
                sum -= nums[left];
                left++;
            }
            ans += (right - left +1);
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal) - atmost(nums,goal-1);
        // int left = 0, right = 0, n = nums.size(),sum = 0,ans=0;

        // while(right<n){
        //     sum += nums[right];

        //     while(sum==goal){
        //         ans++;
        //         sum -= nums[left];
        //         left++;
        //     }
        //     right++;
        // }
        // return ans;
    }
};