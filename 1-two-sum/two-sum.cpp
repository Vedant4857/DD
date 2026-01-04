class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map <int,int> vedant;
        for(int i =0;i<n;i++){
            int z = target - nums[i];
            if(vedant.count(z)){
                return {vedant[z],i};
            }
            vedant[nums[i]] = i;
        }
        return {};
    }
};