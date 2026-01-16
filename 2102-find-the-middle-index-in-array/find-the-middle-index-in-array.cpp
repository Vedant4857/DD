class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int i = 0;
        int sum = 0;
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        while(i<n){
            if(totalsum - nums[i] - sum == sum){
                return i;
            }
            sum += nums[i];
            i++;
        }
        return -1;
    }
};