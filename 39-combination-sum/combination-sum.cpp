class Solution {
public:
    void vedant(vector<int>& c,int index, int n, int sum,vector<int> subans,vector<vector<int>> &ans, int target){

        if(index==n || sum>target){
            if(sum==target){
                ans.push_back(subans);
            }
            return;
        }
        subans.push_back(c[index]);
        vedant(c,index,n,sum+c[index],subans,ans,target);
        subans.pop_back();
        vedant(c,index+1,n,sum,subans,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vedant(candidates,0,candidates.size(),0,{},ans,target);

        return ans;
    }
};