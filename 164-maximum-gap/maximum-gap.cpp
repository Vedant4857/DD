class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        sort(nums.begin(),nums.end());

        int max = nums[1] - nums[0];
        for(int i = 1;i<n;i++){
            if(max < (nums[i]-nums[i-1])) 
                max = (nums[i]-nums[i-1]);
        }
        return max;
    }
};