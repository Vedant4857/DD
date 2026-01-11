class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> vedant;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            if(vedant.count(nums[i])){
                if(i - vedant[nums[i]] <=k) return true;
            }
            vedant[nums[i]] = i;
        }
        return false;
    }
};