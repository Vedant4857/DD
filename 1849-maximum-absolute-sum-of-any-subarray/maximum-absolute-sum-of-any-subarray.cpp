class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        long long maxi = INT_MIN;
        long long mini = INT_MAX;
        long long sum1 = 0, sum2 = 0;
        int n = nums.size();
        int i = 0;

        while(i<n){
            sum1 += nums[i];
            if(sum1<0) sum1 = 0;
            maxi = max(sum1,maxi);

            sum2 += nums[i];
            if(sum2>0) sum2 = 0;
            mini = min(sum2,mini);

            i++;
        }
        return max(maxi,abs(mini));

        

    }
};