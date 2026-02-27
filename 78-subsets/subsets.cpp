class Solution {
public:
    void subset(vector<int>& nums,int index,int n,vector<int> subans,vector<vector<int>>& ans){
        if(index==n){
            ans.push_back(subans);
            return;
        }
        subans.push_back(nums[index]);
        subset(nums,index+1,n,subans,ans);
        subans.pop_back();
        subset(nums,index+1,n,subans,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        subset(nums,0,nums.size(),{},ans);

        return ans;
    }
};