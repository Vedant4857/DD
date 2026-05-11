class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) {
            return 0;
        }
        // if(n==k){
        //     return 1;
        // }
        int div = n/k;

        // 12
        // 4
        // 7(4) 3(2) 6(1) 8(3) 9(2)
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        for (auto y : freq) {
            if (y.second > div) {
                return 0;
            }
        }
        return 1;
    }
};