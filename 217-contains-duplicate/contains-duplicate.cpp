class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicate;
        for(int x : nums){
            if(duplicate.count(x)){
                return 1;
            }
            duplicate.insert(x);
        }
        return 0;
    }
};