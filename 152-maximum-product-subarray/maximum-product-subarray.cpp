class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxi = nums[0], mini = nums[0], ans = nums[0];

        for(int i =1;i<n;i++){
            int x = nums[i];

            if(x<0) swap(maxi,mini);

            maxi = max(x,x*maxi);
            mini = min(x,x*mini);

            ans = max(ans,maxi);
        }
        return ans;
    }
};