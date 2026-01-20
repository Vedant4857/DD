class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long count = 0;
        long long totalsum = accumulate(nums.begin(),nums.end(),(long long)0);
        for(int i = 0;i<n-1;i++){
            sum += nums[i];
            if(sum >= totalsum - sum){
                count++;
            }
        }
        return count;
    }
};