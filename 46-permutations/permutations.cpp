class Solution {
public:
    void vedant(vector<int>& nums, int index, int n, vector<vector<int>>& ans){
        if(index==n-1){
            ans.push_back(nums);
            return;
        }
        for(int i = index;i<n;i++){
            swap(nums[index],nums[i]);
            vedant(nums,index+1,n,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vedant(nums,0,nums.size(),ans);

        return ans;
    }
};