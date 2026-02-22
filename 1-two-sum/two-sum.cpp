class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map <int,int> vedant;
    int n = nums.size();

    for(int i =0;i<n;i++){
        int target2 = target-nums[i];

        if(vedant.count(target2)){
            return {vedant[target2],i};
        }
        else{
            vedant[nums[i]] = i;
        }
    }
    return {};

}
};