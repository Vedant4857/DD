class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set <int> vedant;
        // int max = *max_element(nums.begin(),nums.end());

        for(int x: nums){
            vedant.insert(x);
        }

        for(int i = 1; i<INT_MAX;i++){
            if(vedant.count(i)) continue;
            else return i;
        }
        return 0;
    }
};